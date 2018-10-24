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
  if(state1->handCount[playerIndex] == 7) {
    printf("PASS: cardEffect(smithy): handCount is seven\n");
  } else{
    printf("FAIL: cardEffect(smithy): handCount is not seven.\n");
  }
  if(state1->playedCardCount == 1) {
    printf("PASS: cardEffect(smithy): playerCardCount has increased by one.\n");
  } else{
    printf("FAIL: cardEffect(smithy): playerCardCount has increased by one.\n");
  }
  if(state1->discardCount[playerIndex] == 1) {
    printf("PASS: cardEffect(smithy): only one card was played.\n");
  } else{ 
    printf("FAIL: cardEffect(smithy): something other than one card was played.\n");
  }
  if(state1->discard[playerIndex][0] == smithy) {
    printf("PASS: cardEffect(smithy): the smithy card was discarded.\n");
  } else{ 
    printf("FAIL: cardEffect(smithy): the smithy card was not discarded.\n");
  }

}

