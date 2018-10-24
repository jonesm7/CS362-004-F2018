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
  int i;
  for(i = 0; i < 5; i++) {
    state1->hand[playerIndex][i] = smithy;
  }
  state1->deck[playerIndex][state1->deckCount[playerIndex]] = copper;
  cardEffect(village, -1, -1, -1, state1, 0, NULL);
  if(state1->handCount[playerIndex] == 5) {
    printf("PASS: cardEffect(village): handCount is 5.\n");
  } else{
    printf("FAIL: cardEffect(village): handCount is not 5.\n");
  }
  if(state1->hand[playerIndex][4] == copper) {
    printf("PASS: cardEffect(village): last card is a copper.\n");
  } else{
    printf("FAIL: cardEffect(village): last card is not a copper.\n");
  }
  if(state1->numActions == 3) {
    printf("PASS: cardEffect(village): numActions is 3.\n");
  } else{
    printf("FAIL: cardEffect(village): numActions is not 3.\n");
  }
}

