
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
  if(result1 == 1) {
    printf("PASS: isGameOver: TRUE when province cards have all been used");
  } else{
    printf("FAIL: isGameOver: FALSE when province cards ahve all been used.");
  }
  
  struct gameState* state2 = malloc(sizeof(struct gameState));
  for (i = 0; i < 25; i++) {
    state2->supplyCount[i] = 10;
  }
  state2->supplyCount[adventurer] = 0;
  state2->supplyCount[smithy] = 0;
  state2->supplyCount[village] = 0;
  int result2 = isGameOver(state2);
  if(result2 == 1) {
    printf("PASS: isGameOver: TRUE when three card types have been completely used up.");
  } else{
    printf("FAIL: isGameOver: FALSE when three card types have been completely used up.");
  }
  
  struct gameState* state3 = malloc(sizeof(struct gameState));
  for (i = 0; i < 25; i++) {
    state3->supplyCount[i] = 10;
  }
  int result3 = isGameOver(state3);
  if(result3 == 0) {
    printf("PASS: isGameOver: FALSE when no cards are all used up.");
  } else{
    printf("FAIL: isGameOver: TRUE when no cards are all used up.");
  }
}
