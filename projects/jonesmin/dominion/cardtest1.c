#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

/*
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
{
  // ...
  
  case smithy:
    //+3 Cards
    for (i = 0; i < 3; i++)
      {
        drawCard(currentPlayer, state);
      }
                      
    //discard card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;

  // ...
}
*/

void checkIntEquals(int expected, int actual, char* description) {
  if (expected == actual) {
    printf("PASS: %s: (%d)\n", description, actual);
  } else {
    printf("FAIL: %s: expected != actual (%d != %d)\n", description, expected, actual);
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
  state1->hand[playerIndex][0] = smithy;
  cardEffect(smithy, -1, -1, -1, state1, 0, NULL);
  checkIntEquals(7, state1->handCount[playerIndex], "cardEffect(smithy): handCount");
  checkIntEquals(1, state1->playedCardCount, "cardEffect(smithy): played card count");
  checkIntEquals(smithy, state1->playedCards[0], "cardEffect(smithy): discarded card");
}

