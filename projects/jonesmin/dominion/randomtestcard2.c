
/*
int remodelCardEffect(struct gameState *state, int currentPlayer, int choice1, int choice2,int handPos) {
int j;
int i;
   j = state->hand[currentPlayer][choice1];  //store card we will trash

      if ( (getCost(state->hand[currentPlayer][choice1]) + 2) > getCost(choice2) + 1 )
        {
          return -1;
        }

      gainCard(choice2, state, 0, currentPlayer);

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
}

- randomize choice of card in hand
- randomize choice of replacement card

*/

int run() {
  srand(time(0));
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  int i;
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int randomSeed = 2;
  int numPlayers = 2;
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);

  state1->handCount[playerIndex] = 5;
  int originalHandSize = state1->handCount[playerIndex];

  for(i = 0; i < originalHandSize; i++) {
    int cardType = rand()% treasure_map + 1;
    state1->hand[playerIndex][i] = cardType;
  }
  
  int remodelIndex = rand()% originalHandSize;
  state1->hand[playerIndex][remodelIndex] = remodel;
  
  int inputCard = rand()% 5;
  
  int inputCardType = state1->hand[playerIndex][inputCard];
  
  int outputCardType = rand()% treasure_map + 1;
  
  int returnValue = cardEffect(remodel, inputCard, outputCardType, -1, state1, remodelIndex, NULL);
  
  if(getCost(inputCardType) + 2 <= getCost(outputCardType) && inputCard != remodelIndex) {
    checkIntEquals(0, returnValue);
    checkIntEqulas(originalHandSize - 1, state1->handCount[playerIndex]);
  } else {
    checkIntEquals(-1, returnValue);
    checkIntEquals(originalHandSize, state1->handCount[playerIndex]);
  }
}

int main() {
  int i;
  for(i = 0; i < 10000; i++) {
    run();
  }
}