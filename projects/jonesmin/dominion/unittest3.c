
/*
int updateCoins(int player, struct gameState *state, int bonus)
{
  int i;
	
  //reset coin count
  state->coins = 0;

  //add coins for each Treasure card in player's hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == copper)
	{
	  state->coins += 1;
	}
      else if (state->hand[player][i] == silver)
	{
	  state->coins += 2;
	}
      else if (state->hand[player][i] == gold)
	{
	  state->coins += 3;
	}	
    }	

  //add bonus
  state->coins += bonus;

  return 0;
}
*/

int main() {
  testCoin(smithy, 0, 0);
  testCoin(copper, 1, 0);
  testCoin(silver, 2, 0);
  testCoin(gold, 3, 0);
  testCoin(smithy, 4, 4);
}

void testCoin(int cardType, int coinAmount, int bonus) {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 1;
  state1->hand[playerIndex][0] = cardType;
  updateCoins(playerIndex, state1, bonus);
  if(state1->coins == coinAmount) {
    printf("PASS: updateCoins: coins for cardType %d and bonus %d is %d.", cardType, bonus, coinAmount);
  } else {
    printf("FAIL: updateCoins: coins for cardType %d and bonus %d is %d.", cardType, bonus, coinAmount);
  }
}