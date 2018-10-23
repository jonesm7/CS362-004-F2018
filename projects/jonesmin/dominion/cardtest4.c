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

int main() {
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int randomSeed = 2;
  int numPlayers = 2;
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  int 1;
  for(i = 0; i < 5; i++) {
    state1->hand[payerIndex][i] = smithy;
  }
  state1->deck[playerIndex][state1->deckCount[playerIndex]] = copper;
  cardEffect(village, -1, -1, -1, state1, 0, NULL);
  if(state1->handcount == 5) {
    printf("PASS: cardEffect(village): handCount is 5.");
  } else{
    printf("FAIL: cardEffect(village): handCount is not 5.");
  }
  if(state1->hand[4] == copper) {
    printf("PASS: cardEffect(village): last card is a copper.");
  } else{
    printf("FAIL: cardEffect(village): last card is not a copper.");
  }
  if(state1->numActions == 3) {
    printf("PASS: cardEffect(village): numActoins is 3.");
  } else{
    printf("FAIL: cardEffect(village): numActoins is not 3.");
  }
}

