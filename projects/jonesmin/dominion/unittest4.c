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

int main() {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int handPos1 = 0;
  state1->handCount[playerIndex] = 1;
  state1->hand[playerIndex][handPos1] = smithy;
  discardCard(handPos1, playerIndex, state1, 1);
  if(state1->hand[playerIndex][handPos1] == -1) {
    printf("PASS: discardCard: discarded card is -1.");
  } else {
    printf("FAIL: discardCard: discarded card is not -1.");
  }
  if (state1->handCount[playerIndex] == 0) {
    printf("PASS: discardCard: hand size is 0.");
  } else {
    printf("FAIL: discardCard: hand size is not 0.");
  }
  state1->handCount[playerIndex] = 2;
  state1->hand[playerIndex][handPos1] = smithy;
  state1->hand[playerIndex][1] = copper;
  state1->playedCardCount = 0;
  discardCard(handPos1, playerIndex, state1, 0);
  if(state1->hand[playerIndex][handPos1] == copper) {
    printf("PASS: discardCard: discarded card is copper.");
  } else {
    printf("FAIL: discardCard: discarded card is not copper.");
  }
  if(state1->hand[playerIndex][1] == -1) {
    printf("PASS: discardCard: discarded card is -1.");
  } else {
    printf("FAIL: discardCard: discarded card is not -1.");
  }
  if (state1->handCount[playerIndex] == 1) {
    printf("PASS: discardCard: hand size is 1.");
  } else {
    printf("FAIL: discardCard: hand size is not 1.");
  }
  if(state1->playedCardCount == 1) {
    printf("PASS: discardCard: played card count is 1.");  
  } else {
    printf("FAIL: discardCard: played card count is not 1.");
  }
  if(state1->playedCards[0] == smithy) {
    printf("PASS: discardCard: played card is smithy."); 
  } else {
    printf("FAIL: discardCard: played card count is not smithy."); 
  }
}
