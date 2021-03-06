#include <stdlib.h>     // srand, rand
#include <stdio.h>
#include <time.h>       // time
#include "dominion.h"
#include "testhelpers.h"

void run() {
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  int i;
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int randomSeed = 2;
  int numPlayers = 2;
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);

  int treasureCards = 0;
  int treasureCardTypes[3];
  for(i = 0; i < 3; i++) {
    treasureCardTypes[i] = 0;
  }
  state1->handCount[playerIndex] = 5;
  int originalHandSize = state1->handCount[playerIndex];
  int mineIndex = rand()% originalHandSize;
  for(i = 0; i < 5; i++) {
    int cardType;
    if (i == mineIndex) {
      cardType = mine;
    } else {
      int cardClass = rand()% 3;
      // card class 0: treasure
      if(cardClass == 0) {
        cardType = copper + rand()% 3;
        treasureCards ++;
        treasureCardTypes[cardType - copper] ++;
      } else if(cardClass == 1) {
        cardType = curse + rand()% 4;
      } else {
        cardType = adventurer + rand()% 20;
      }
    }
    state1->hand[playerIndex][i] = cardType;
  }
  int inputCard = rand()% 5;
  
  int inputCardType = state1->hand[playerIndex][inputCard];
  if(inputCardType == copper || inputCardType == silver) {
    int choiceValidity = rand() % 2;
    if(choiceValidity == 1) {
      int outputCardType = inputCardType + 1;
      cardEffect(mine, inputCard, outputCardType, -1, state1, mineIndex, NULL);
      checkIntEquals(originalHandSize - 1, state1->handCount[playerIndex],
                     "randomtestcard1: input valid: checking handCount");
      int newTreasureCardTypes[3];
      for(i = 0; i < 3; i++) {
        newTreasureCardTypes[i] = 0;
      }
      for(i = 0; i < state1->handCount[playerIndex]; i ++) {
        if (state1->hand[playerIndex][i] >= copper && state1->hand[playerIndex][i] <= gold) {
          int cardTypeIndex = state1->hand[playerIndex][i] - copper;
          newTreasureCardTypes[cardTypeIndex] ++;
        }
      }
      
      treasureCardTypes[inputCardType - copper] --;
      treasureCardTypes[outputCardType - copper] ++;
      for(i = 0; i < 3; i++){
        checkIntEquals(treasureCardTypes[i], newTreasureCardTypes[i],
                       "randomtestcard1: input valid: checking card");
      }
    } else { 
      int outputCardType = (rand()% (treasure_map + 2)) - 1;
      if(outputCardType == inputCardType + 1) {
        outputCardType = treasure_map + 1;
      }
      int returnValue = cardEffect(mine, inputCard, outputCardType, -1, state1, mineIndex, NULL);
      checkIntEquals(-1, returnValue, "randomtestcard1: invalid replacement: checking return value");
      checkIntEquals(originalHandSize, state1->handCount[playerIndex],
                     "randomtestcard1: invalid replacement: checking handCount");
      if (returnValue != -1) {
        printf("input: %d, output: %d\n", inputCardType, outputCardType);
      }
    }
  } else {
    int outputCardType = (rand()% (treasure_map + 2)) - 1;

    int returnValue = cardEffect(mine, inputCard, outputCardType, -1, state1, mineIndex, NULL);
    checkIntEquals(-1, returnValue, "randomtestcard1: invalid input card: checking return value");
    checkIntEquals(originalHandSize, state1->handCount[playerIndex],
                   "randomtestcard1: invalid input card: checking handCount");
  }

}

int main() {
  srand(time(0));
  int i;
  for(i = 0; i < 10000; i++) {
    run();
  }
  return 0;
}
