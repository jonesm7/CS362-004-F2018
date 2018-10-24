#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

/*
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
{
  // ...
  
    case adventurer:
      while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
          shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
          drawntreasure++;
        else{
          temphand[z]=cardDrawn;
          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
          z++;
        }
      }
      while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
      }
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
  for(i = 0; i < state1->deckCount[playerIndex]; i++) {
    state1->deck[playerIndex][i] = copper;
  }
  cardEffect(adventurer, -1, -1, -1, state1, 0, NULL);
  if(state1->handCount[playerIndex] == 6) {
    printf("PASS: cardEffect(adventurer): handCount is 6\n");
  } else{
    printf("FAIL: cardEffect(adventurer): handCount is not 6.\n");
  }
  if(state1->hand[playerIndex][5] == copper) {
    printf("PASS: cardEffect(adventurer): last card is a copper.\n");
  } else{
    printf("FAIL: cardEffect(adventurer): last card is not a copper.\n");
  }
  if(state1->discardCount[playerIndex] == 1) {
    printf("PASS: cardEffect(adventurer): only 1 card was played.\n");
  } else{ 
    printf("FAIL: cardEffect(adventurer): something other than 1 card was played.\n");
  }
  if(state1->discard[playerIndex][0] == adventurer) {
    printf("PASS: cardEffect(adventurer): the adventurer card was discarded.\n");
  } else{ 
    printf("FAIL: cardEffect(adventurer): the adventurer card was not discarded.\n");
  }
  
   initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  for(i = 0; i < state1->deckCount[playerIndex]; i++) {
    state1->deck[playerIndex][i] = silver;
  }
  state1->deck[playerIndex][state1->deckCount[playerIndex]-1] = smithy;
  cardEffect(adventurer, -1, -1, -1, state1, 0, NULL);
  if(state1->handCount[playerIndex] == 6) {
    printf("PASS: cardEffect(adventurer): handCount is 6\n");
  } else{
    printf("FAIL: cardEffect(adventurer): handCount is not 6.\n");
  }
  if(state1->hand[playerIndex][5] == silver) {
    printf("PASS: cardEffect(adventurer): last card is a silver.\n");
  } else{
    printf("FAIL: cardEffect(adventurer): last card is not a silver.\n");
  }
  if(state1->discardCount[playerIndex] == 2) {
    printf("PASS: cardEffect(adventurer): 2 cards were played.\n");
  } else{ 
    printf("FAIL: cardEffect(adventurer): something other than 2 cards were played.\n");
  }
  if(state1->discard[playerIndex][0] == smithy) {
    printf("PASS: cardEffect(adventurer): the smithy card was discarded.\n");
  } else{ 
    printf("FAIL: cardEffect(adventurer): the smithy card was not discarded.\n");
  }
    
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  for(i = 0; i < state1->deckCount[playerIndex]; i++) {
    state1->deck[playerIndex][i] = smithy;
  }
  cardEffect(adventurer, -1, -1, -1, state1, 0, NULL);
  if(state1->handCount[playerIndex] == 4) {
    printf("PASS: cardEffect(adventurer): handCount is 4\n");
  } else{
    printf("FAIL: cardEffect(adventurer): handCount is not 4.\n");
  }
  

}

