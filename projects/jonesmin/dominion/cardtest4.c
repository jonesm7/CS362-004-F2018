#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

/*
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
{
  // ...

    case village:
      //+1 Card
      drawCard(currentPlayer, state);
                        
      //+2 Actions
      state->numActions = state->numActions + 2;
                        
      //discard played card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
      
  // ...
}
*/

int anyFailed = 0;

void checkIntEquals(int expected, int actual, char* description) {
  if (expected == actual) {
    printf("PASS: %s: (%d)\n", description, actual);
  } else {
    printf("FAIL: %s: expected != actual (%d != %d)\n", description, expected, actual);
    anyFailed = 1;
  }
}

int main() {
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int randomSeed = 2;
  int numPlayers = 2;
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  int i;
  for(i = 0; i < 5; i++) {
    state1->hand[playerIndex][i] = smithy;
  }
  state1->deck[playerIndex][state1->deckCount[playerIndex]] = copper;
  cardEffect(village, -1, -1, -1, state1, 0, NULL);
  checkIntEquals(5, state1->handCount[playerIndex], "cardEffect(village): handCount");
  checkIntEquals(copper, state1->hand[playerIndex][0], "cardEffect(village): first card");
  checkIntEquals(3, state1->numActions, "cardEffect(village): numActions");
  
  if (!anyFailed) {
    printf("TEST SUCCESSFULLY COMPLETED\n");
  } else {
    printf("TEST FAILED\n");
  }
}

