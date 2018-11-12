#include <stdlib.h>     // srand, rand
#include <stdio.h>
#include <time.h>       // time
#include "dominion.h"
#include "testhelpers.h"

/*
int adventurerCardEffect(struct gameState *state, int currentPlayer) {
          int drawntreasure=0;
          int cardDrawn;
          int temphand[MAX_HAND];
          int z = 0;
          

       while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
          shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver)
          drawntreasure++;
        else{
          temphand[z]=cardDrawn;
          state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
          z++;
        }
      }
      while(z-2 >= 0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
      }
      return 0;
}
*/

void run() {
  int kingdomCards[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
           sea_hag, tribute, smithy};

  int i;
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  int randomSeed = 2;
  int numPlayers = 2;
  
  initializeGame(numPlayers, kingdomCards, randomSeed, state1);
  int originalHandSize = state1->handCount[playerIndex];
  int deckSize = rand()% 10;
  int treasureCardsInDeck = 0;
  int nonTreasureCardsToDraw = 0;
  state1->deckCount[playerIndex] = deckSize;
  for(i = deckSize - 1; i >= 0; i--) {
     int cardClass = rand()% 3;
     int cardType;
     // card class 0: treasure
     if(cardClass == 0) {
       cardType = copper + rand()% 3;
       if(treasureCardsInDeck < 2) {
         treasureCardsInDeck += 1;
       }
     } else if(cardClass == 1) {
       cardType = curse + rand()% 4;
       if(treasureCardsInDeck < 2) {
         nonTreasureCardsToDraw += 1;
       }
     } else {
       cardType = adventurer + rand()% 20;
       if(treasureCardsInDeck < 2) {
         nonTreasureCardsToDraw += 1;
       }
     }
     state1->deck[playerIndex][i] = cardType;
  }
   
  int discardPileSize = rand()% 10;
  int treasureCardsInDiscard = 0;
  state1->discardCount[playerIndex] = discardPileSize;
  int adventurerIndex = rand()% originalHandSize;
  for(i = 0; i < discardPileSize; i++) {
     int cardType;
     if(i == adventurerIndex) {
       cardType = adventurer;
     } else {
       
       int cardClass = rand()% 3;
       // card class 0: treasure
       if(cardClass == 0) {
         cardType = copper + rand()% 3;
         if(treasureCardsInDeck + treasureCardsInDiscard < 2) {
           treasureCardsInDiscard += 1;
         }
       } else if(cardClass == 1) {
         cardType = curse + rand()% 4;
       } else {
         cardType = adventurer + rand()% 20;
       }
     }
     state1->discard[playerIndex][i] = cardType;
  }
  cardEffect(adventurer, -1, -1, -1, state1, adventurerIndex, NULL);

  if(treasureCardsInDeck == 2) {
    checkIntEquals(deckSize - treasureCardsInDeck - nonTreasureCardsToDraw, state1->deckCount[playerIndex],
                   "randomtestadventurer: treasureCardsInDeck == 2: checking deckCount");
    // check that discard pile has non treasure cards that were discarded
    checkIntEquals(discardPileSize + nonTreasureCardsToDraw, state1->discardCount[playerIndex],
                   "randomtestadventurer: treasureCardsInDeck == 2: checking discardCount"); 
    // check that hand count is found treasure card count
    checkIntEquals(originalHandSize + treasureCardsInDeck - 1, state1->handCount[playerIndex],
                   "randomtestadventurer: treasureCardsInDeck == 2: checking handCount");
    checkIntEquals(1, state1->playedCardCount, "randomtestadventurer: treasureCardsInDeck == 2: checking playedCardCount");
  } else {
    // check that final deck + discard is original minus found treasure card count
    checkIntEquals(deckSize + discardPileSize - treasureCardsInDeck - treasureCardsInDiscard,
                   state1->deckCount[playerIndex] + state1->discardCount[playerIndex],
                   "randomtestadventurer: treasureCardsInDeck < 2: checking deckCount + discardCount");
    // check that hand count is original plus found treasure cards minus the adventurer
    checkIntEquals(originalHandSize + treasureCardsInDeck + treasureCardsInDiscard - 1,
                   state1->handCount[playerIndex],
                   "randomtestadventurer: treasureCardsInDeck < 2: checking handCount");
    checkIntEquals(1, state1->playedCardCount, "randomtestadventurer: treasureCardsInDeck < 2: checking playedCardCount");
  }
}

int main() {
  srand(time(0));
  int i;
  for(i = 0; i < 10000; i++) {
    run();
  }
  return 0;
}
