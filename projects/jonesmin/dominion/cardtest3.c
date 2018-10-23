
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
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = copper;
  int i;
  for( i = 2; i < 5; i++) {
    state1->hand[playerIndex][i] = estate;
  }
    
  cardEffect(mine, 1, silver, -1, state1, 0, NULL);

  if(state1->handCount[playerIndex] == 4) {
    printf("PASS: cardEffect(mine): handCount is 4");
  } else{
    printf("FAIL: cardEffect(mine): handCount is not 4.");
  }
  if(state1->hand[playerIndex][3] == silver) {
    printf("PASS: cardEffect(mine): last card is a silver.");
  } else{
    printf("FAIL: cardEffect(mine): last card is not a silver.");
  }
  if(state1->playedCardCount == 1) {
    printf("PASS: cardEffect(mine): only one card was played.");
  } else{ 
    printf("FAIL: cardEffect(mine): something other than one card was played.")
  }
  if(state1->playedCard[0] == mine) {
    printf("PASS: cardEffect(mine): the mine card was discarded.");
  } else{ 
    printf("FAIL: cardEffect(mine): the mine card was not discarded.")
  }
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = smithy;
    
  int return1 = cardEffect(mine, 1, silver, -1, state1, 0, NULL);
  if(return1 == -1) {
    printf("PASS: cardEffect(mine): coverting wrong type returns -1.");
  } else{
    printf("FAIL: cardEffect(mine): coverting wrong type does not return -1.");
  }
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = silver;
    
  int return2 = cardEffect(mine, 1, duchy, -1, state1, 0, NULL);
  if(return2 == -1) {
    printf("PASS: cardEffect(mine): choosing a non treasure card returns -1.");
  } else{
    printf("FAIL: cardEffect(mine): choosing a non treasure card does not return -1.");
  }
    
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  state1->hand[playerIndex][0] = mine;
  state1->hand[playerIndex][1] = copper;
    
  int return3 = cardEffect(mine, 1, gold, -1, state1, 0, NULL);
  if(return3 == -1) {
    printf("PASS: cardEffect(mine): choosing treasure with too high a value returns -1.");
  } else{
    printf("FAIL: cardEffect(mine): choosing treasure with too high a value does not return -1.");
  }
}
