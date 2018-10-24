#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "testhelpers.h"

/*
int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
{
  // ...

    case mine:
      j = state->hand[currentPlayer][choice1];  //store card we will trash

      if (state->hand[currentPlayer][choice1] < copper || state->hand[currentPlayer][choice1] > gold)
        {
          return -1;
        }
                
      if (choice2 > treasure_map || choice2 < curse)
        {
          return -1;
        }

      if ( (getCost(state->hand[currentPlayer][choice1]) + 3) > getCost(choice2) )
        {
          return -1;
        }

      gainCard(choice2, state, 2, currentPlayer);

      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);

      //discard trashed card
      for (i = 0; i < state->handCount[currentPlayer]; i++)
        {
          if (state->hand[currentPlayer][i] == j)
            {
              discardCard(i, currentPlayer, state, 0);                        
              break;
            }
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
  int initialSilver = state1->supplyCount[silver];
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = copper;
  int i;
  for( i = 2; i < 5; i++) {
    state1->hand[playerIndex][i] = estate;
  }
    
  cardEffect(mine, 1, silver, -1, state1, 0, NULL);
  checkIntEquals(4, state1->handCount[playerIndex], "cardEffect(mine): handCount");
  checkIntEquals(silver, state1->hand[playerIndex][0], "cardEffect(mine): first card");
  checkIntEquals(estate, state1->hand[playerIndex][1], "cardEffect(mine): second card");
  checkIntEquals(1, state1->playedCardCount, "cardEffect(mine): played card count");
  checkIntEquals(mine, state1->playedCards[0], "cardEffect(mine): discarded card");
  checkIntEquals(initialSilver - 1, state1->supplyCount[silver], "cardEffect(mine): supply for silver");
  // check the other player's hand
  checkIntEquals(0, state1->handCount[1], "cardEffect(mine): other player's hand");
  // check supply piles that shouldn't change
  checkCardPilesDontChange(state1, 1, 1, 0);

  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = smithy;
    
  int return1 = cardEffect(mine, 1, silver, -1, state1, 0, NULL);
  checkIntEquals(-1, return1, "cardEffect(mine): converting wrong type");
  // check the other player's hand
  checkIntEquals(0, state1->handCount[1], "cardEffect(mine): other player's hand");
  // check supply piles that shouldn't change
  checkCardPilesDontChange(state1, 1, 1, 1);

  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = silver;
    
  int return2 = cardEffect(mine, 1, duchy, -1, state1, 0, NULL);
  checkIntEquals(-1, return2, "cardEffect(mine): choosing a non treasure card");
  // check the other player's hand
  checkIntEquals(0, state1->handCount[1], "cardEffect(mine): other player's hand");
  // check supply piles that shouldn't change
  checkCardPilesDontChange(state1, 1, 1, 1);

  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = copper;
    
  int return3 = cardEffect(mine, 1, gold, -1, state1, 0, NULL);
  checkIntEquals(-1, return3, "cardEffect(mine): choosing treasure with too high a value");
  // check the other player's hand
  checkIntEquals(0, state1->handCount[1], "cardEffect(mine): other player's hand");
  // check supply piles that shouldn't change
  checkCardPilesDontChange(state1, 1, 1, 1);

  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = silver;
    
  int return4 = cardEffect(mine, 1, -1, -1, state1, 0, NULL);
  checkIntEquals(-1, return4, "cardEffect(mine): choosing an invalid card to convert to.");
  // check the other player's hand
  checkIntEquals(0, state1->handCount[1], "cardEffect(mine): other player's hand");
  // check supply piles that shouldn't change
  checkCardPilesDontChange(state1, 1, 1, 1);
  
  if (!getAnyFailed()) {
    printf("TEST SUCCESSFULLY COMPLETED\n");
  } else {
    printf("TEST FAILED\n");
  }
}
