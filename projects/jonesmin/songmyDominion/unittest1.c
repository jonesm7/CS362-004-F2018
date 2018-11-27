#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"
#include "testhelpers.h"
#include "testhelpers.h"

/*
int isGameOver(struct gameState *state) {
  int i;
  int j;
	
  //if stack of Province cards is empty, the game ends
  if (state->supplyCount[province] == 0)
    {
      return 1;
    }

  //if three supply pile are at 0, the game ends
  j = 0;
  for (i = 0; i < 25; i++)
    {
      if (state->supplyCount[i] == 0)
	{
	  j++;
	}
    }
  if ( j >= 3)
    {
      return 1;
    }

  return 0;
}
*/

int main() {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  state1->supplyCount[province] = 0;
  int result1 = isGameOver(state1);
  checkIntEquals(1, result1, "isGameOver: when province cards ahve all been used");
  
  struct gameState* state2 = malloc(sizeof(struct gameState));
  int i;
  for (i = 0; i < 25; i++) {
    state2->supplyCount[i] = 10;
  }
  state2->supplyCount[adventurer] = 0;
  state2->supplyCount[smithy] = 0;
  state2->supplyCount[village] = 0;
  int result2 = isGameOver(state2);
  checkIntEquals(1, result2, "isGameOver: when three card types have been completely used up");
  
  struct gameState* state3 = malloc(sizeof(struct gameState));
  for (i = 0; i < 25; i++) {
    state3->supplyCount[i] = 10;
  }
  int result3 = isGameOver(state3);
  checkIntEquals(0, result3, "isGameOver: when no cards are all used up");
  
  if (!getAnyFailed()) {
    printf("TEST SUCCESSFULLY COMPLETED\n");
  } else {
    printf("TEST FAILED\n");
  }
}
