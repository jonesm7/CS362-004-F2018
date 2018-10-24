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

int anyFailed = 0;

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

int main() {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int randomSeed = 2;
  int numPlayers = 2;
  initializeGame(numPlayers, gameKingdomCards, randomSeed, state1);
  int deckCount = state1->deckCount[playerIndex];
  // set top 3 cards in deck to cards we control
  state1->deck[playerIndex][deckCount-1] = baron;
  state1->deck[playerIndex][deckCount-2] = great_hall;
  state1->deck[playerIndex][deckCount-3] = minion;
  state1->hand[playerIndex][0] = smithy;
  cardEffect(smithy, -1, -1, -1, state1, 0, NULL);
  checkIntEquals(7, state1->handCount[playerIndex], "cardEffect(smithy): handCount");
  // check top 3 cards in hand
  int handCount = state1->handCount[playerIndex];
  checkIntEquals(baron, state1->hand[playerIndex][handCount-1], "cardEffect(smithy): hand[-1]");
  checkIntEquals(great_hall, state1->hand[playerIndex][handCount-2], "cardEffect(smithy): hand[-2]");
  checkIntEquals(minion, state1->hand[playerIndex][handCount-3], "cardEffect(smithy): hand[-3]");
  checkIntEquals(1, state1->playedCardCount, "cardEffect(smithy): played card count");
  checkIntEquals(smithy, state1->playedCards[0], "cardEffect(smithy): discarded card");
  // check the other player's hand
  checkIntEquals(0, state1->handCount[1], "cardEffect(smithy): other player's hand");
  // check supply piles that shouldn't change
  checkCardPilesDontChange(state1, 1, 1, 1);
  
  if (!anyFailed) {
    printf("TEST SUCCESSFULLY COMPLETED\n");
  } else {
    printf("TEST FAILED\n");
  }
}

