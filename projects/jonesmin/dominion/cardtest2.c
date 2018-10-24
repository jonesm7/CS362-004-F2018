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
  int i;
  for(i = 0; i < state1->deckCount[playerIndex]; i++) {
    state1->deck[playerIndex][i] = copper;
  }
  cardEffect(adventurer, -1, -1, -1, state1, 0, NULL);
  checkIntEquals(6, state1->handCount[playerIndex], "cardEffect(adventurer): handCount");
  checkIntEquals(copper, state1->hand[playerIndex][5], "cardEffect(adventurer): last card");
  checkIntEquals(1, state1->discardCount[playerIndex], "cardEffect(adventurer): discarded count");
  checkIntEquals(adventurer, state1->discard[playerIndex][0], "cardEffect(adventurer): discarded card");
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  for(i = 0; i < state1->deckCount[playerIndex]; i++) {
    state1->deck[playerIndex][i] = silver;
  }
  state1->deck[playerIndex][state1->deckCount[playerIndex]-1] = smithy;
  cardEffect(adventurer, -1, -1, -1, state1, 0, NULL);
  checkIntEquals(6, state1->handCount[playerIndex], "cardEffect(adventurer): handCount");
  checkIntEquals(silver, state1->hand[playerIndex][5], "cardEffect(adventurer): last card");
  checkIntEquals(2, state1->discardCount[playerIndex], "cardEffect(adventurer): discarded count");
  checkIntEquals(smithy, state1->discard[playerIndex][0], "cardEffect(adventurer): discarded card");

  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  for(i = 0; i < state1->deckCount[playerIndex]; i++) {
    state1->deck[playerIndex][i] = smithy;
  }
  cardEffect(adventurer, -1, -1, -1, state1, 0, NULL);
  checkIntEquals(4, state1->handCount[playerIndex], "cardEffect(adventurer): handCount");

}

