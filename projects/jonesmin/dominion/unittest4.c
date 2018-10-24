#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

/*
int discardCard(int handPos, int currentPlayer, struct gameState *state, int trashFlag)
{
	
  //if card is not trashed, added to Played pile 
  if (trashFlag < 1)
    {
      //add card to played pile
      state->playedCards[state->playedCardCount] = state->hand[currentPlayer][handPos]; 
      state->playedCardCount++;
    }
	
  //set played card to -1
  state->hand[currentPlayer][handPos] = -1;
	
  //remove card from player's hand
  if ( handPos == (state->handCount[currentPlayer] - 1) ) 	//last card in hand array is played
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else if ( state->handCount[currentPlayer] == 1 ) //only one card in hand
    {
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
  else 	
    {
      //replace discarded card with last card in hand
      state->hand[currentPlayer][handPos] = state->hand[currentPlayer][ (state->handCount[currentPlayer] - 1)];
      //set last card to -1
      state->hand[currentPlayer][state->handCount[currentPlayer] - 1] = -1;
      //reduce number of cards in hand
      state->handCount[currentPlayer]--;
    }
	
  return 0;
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
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int handPos1 = 0;
  state1->handCount[playerIndex] = 1;
  state1->hand[playerIndex][handPos1] = smithy;
  discardCard(handPos1, playerIndex, state1, 1);
  checkIntEquals(-1, state1->hand[playerIndex][handPos1], "discardCard: discarded card");
  checkIntEquals(0, state1->handCount[playerIndex], "hand size");
  state1->handCount[playerIndex] = 2;
  state1->hand[playerIndex][handPos1] = smithy;
  state1->hand[playerIndex][1] = copper;
  state1->playedCardCount = 0;
  discardCard(handPos1, playerIndex, state1, 0);
  checkIntEquals(copper, state1->hand[playerIndex][handPos1], "discardCard: discarded card [0]");
  checkIntEquals(-1, state1->hand[playerIndex][1], "discardCard: discarded card [1]");
  checkIntEquals(1, state1->handCount[playerIndex], "discardCard: hand size");
  checkIntEquals(1, state1->playedCardCount, "discardCard: played card count");
  checkIntEquals(smithy, state1->playedCards[0], "discardCard: played card");
}
