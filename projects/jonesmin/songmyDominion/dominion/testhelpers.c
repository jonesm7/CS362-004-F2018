#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "testhelpers.h"

int anyFailed = 0;
int getAnyFailed() {
  return anyFailed;
}

void checkIntEquals(int expected, int actual, char* description) {
  if (expected == actual) {
    printf("PASS: %s: (%d)\n", description, actual);
  } else {
    printf("FAIL: %s: expected != actual (%d != %d)\n", description, expected, actual);
    anyFailed = 1;
  }
}

int victoryCards[] = {curse, estate, duchy, province};
int treasureCards[] = {copper, silver, gold};
int gameKingdomCards[] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};


void checkCardPilesDontChange(struct gameState* state, int checkKingdomCards, int checkVictoryCards, int checkTreasureCards) {
  struct gameState* initialState = malloc(sizeof(struct gameState));
  int randomSeed = 2;
  int numPlayers = 2;
  int i;
  initializeGame(numPlayers, gameKingdomCards, randomSeed, initialState);
  if (checkKingdomCards) {
    for (i = 0; i < 10; i++) {
      int card = gameKingdomCards[i];
      printf("Checking kingdom card %d\n", card);
      checkIntEquals(initialState->supplyCount[card], state->supplyCount[card], "Supply - kindgom card");
    }
  }
  if (checkVictoryCards) {
    for (i = 0; i < 4; i++) {
      int card = victoryCards[i];
      printf("Checking victory card %d\n", card);
      checkIntEquals(initialState->supplyCount[card], state->supplyCount[card], "Supply - victory card");
    }
  }
  if (checkTreasureCards) {
    for (i = 0; i < 3; i++) {
      int card = treasureCards[i];
      printf("Checking treasure card %d\n", card);
      checkIntEquals(initialState->supplyCount[card], state->supplyCount[card], "Supply - treasure card");
    }
  }
}
