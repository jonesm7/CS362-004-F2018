#include <stdlib.h>     // srand, rand
#include <stdio.h>
#include <time.h>       // time
#include "dominion.h"
#include "testhelpers.h"

#define KINGDOM_CARDS 10

int isCardInPlay(int kingdomCards[], int cardType) {
  int i;
  if (cardType >= 0 && cardType <= gold) {
    return 1;
  }
  for (i = 0; i < KINGDOM_CARDS; i++) {
    if (kingdomCards[i] == cardType) {
      return 1;
    }
  }
  return 0;
}

void run() {
  int kingdomCards[KINGDOM_CARDS] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  int i;
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int randomSeed = 2;
  int numPlayers = 2;
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);

  state1->handCount[playerIndex] = 5;
  int originalHandSize = state1->handCount[playerIndex];

  for(i = 0; i < originalHandSize; i++) {
    int cardType = rand()% (gold + 1 + KINGDOM_CARDS);
    if (cardType <= gold) {
      state1->hand[playerIndex][i] = cardType;
    } else {
      int kingdomIndex = cardType - gold - 1;
      state1->hand[playerIndex][i] = kingdomCards[kingdomIndex];
    }
  }
  
  int remodelIndex = rand()% originalHandSize;
  state1->hand[playerIndex][remodelIndex] = remodel;
  
  int inputCard = rand()% 5;
  
  int inputCardType = state1->hand[playerIndex][inputCard];
  
  int outputCardType = rand()% treasure_map + 1;
  
  int returnValue = cardEffect(remodel, inputCard, outputCardType, -1, state1, remodelIndex, NULL);
  
  if(getCost(inputCardType) + 2 <= getCost(outputCardType) && inputCard != remodelIndex && isCardInPlay(kingdomCards, outputCardType)) {
    checkIntEquals(0, returnValue, "randomtestcard2: valid remodel: checking return value");
    checkIntEquals(originalHandSize - 2, state1->handCount[playerIndex],
                   "randomtestcard2: valid remodel: checking handCount");
    checkIntEquals(1, state1->playedCardCount, "randomtestcard2: valid remodel: checking playedCardCount");
  } else {
    checkIntEquals(-1, returnValue, "randomtestcard2: invalid remodel: checking return value");
    if (returnValue != -1) {
      printf("  inputCardType = %d, outputCardType = %d\n", inputCardType, outputCardType);
    }
    checkIntEquals(originalHandSize, state1->handCount[playerIndex],
                   "randomtestcard2: invalid remodel: checking handCount");
    checkIntEquals(0, state1->playedCardCount, "randomtestcard2: invalid remodel: checking playedCardCount");
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
