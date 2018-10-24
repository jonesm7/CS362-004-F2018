#include <stdlib.h>
#include <stdio.h>
#include "dominion.h"

/*
int scoreFor (int player, struct gameState *state) {

  int i;
  int score = 0;
  //score from hand
  for (i = 0; i < state->handCount[player]; i++)
    {
      if (state->hand[player][i] == curse) { score = score - 1; };
      if (state->hand[player][i] == estate) { score = score + 1; };
      if (state->hand[player][i] == duchy) { score = score + 3; };
      if (state->hand[player][i] == province) { score = score + 6; };
      if (state->hand[player][i] == great_hall) { score = score + 1; };
      if (state->hand[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    }

  //score from discard
  for (i = 0; i < state->discardCount[player]; i++)
    {
      if (state->discard[player][i] == curse) { score = score - 1; };
      if (state->discard[player][i] == estate) { score = score + 1; };
      if (state->discard[player][i] == duchy) { score = score + 3; };
      if (state->discard[player][i] == province) { score = score + 6; };
      if (state->discard[player][i] == great_hall) { score = score + 1; };
      if (state->discard[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    }

  //score from deck
  for (i = 0; i < state->discardCount[player]; i++)
    {
      if (state->deck[player][i] == curse) { score = score - 1; };
      if (state->deck[player][i] == estate) { score = score + 1; };
      if (state->deck[player][i] == duchy) { score = score + 3; };
      if (state->deck[player][i] == province) { score = score + 6; };
      if (state->deck[player][i] == great_hall) { score = score + 1; };
      if (state->deck[player][i] == gardens) { score = score + ( fullDeckCount(player, 0, state) / 10 ); };
    }

  return score;
}
*/

int anyFailed = 0;

void checkIntEquals(int expected, int actual, char* description) {
  if (expected == actual) {
    printf("PASS: %s: (%d)\n", description, actual);
  } else {
    printf("FAIL: %s: expected != actual (%d != %d)\n", description, expected, actual);
    anyFailed = 1;
  }
}

void testHandCardScore(int card, int score) {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 1;
  state1->hand[playerIndex][0] = card;
  state1->discardCount[playerIndex] = 0;
  state1->deckCount[playerIndex] = 0;
  int result1 = scoreFor(playerIndex, state1);
  printf("Checking score for card type %d\n", card);
  checkIntEquals(score, result1, "scoreFor: score for card in hand");
}
  
void testHandGardenScore() {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 4;
  int i;
  for(i = 0; i < 4; i++) {
    state1->hand[playerIndex][i] = copper;
  }
  state1->discardCount[playerIndex] = 4;
  for(i = 0; i < 4; i++) {
    state1->discard[playerIndex][i] = copper;
  }
  state1->deckCount[playerIndex] = 4;
  for(i = 0; i < 4; i++) {
    state1->deck[playerIndex][i] = copper;
  }
  state1->hand[playerIndex][0] = gardens;
  int result1 = scoreFor(playerIndex, state1);
  int score = 1;
  checkIntEquals(score, result1, "scoreFor: score for gardens in hand");
}
void testDiscardCardScore(int card, int score) {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 0;
  state1->discardCount[playerIndex] = 1;
  state1->discard[playerIndex][0] = card;
  state1->deckCount[playerIndex] = 0;
  int result1 = scoreFor(playerIndex, state1);
  printf("Checking score for card type %d\n", card);
  checkIntEquals(score, result1, "scoreFor: score for card in discard pile");
}
void testDiscardGardenScore() {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 4;
  int i;
  for(i = 0; i < 4; i++) {
    state1->hand[playerIndex][i] = copper;
  }
  state1->discardCount[playerIndex] = 4;
  for(i = 0; i < 4; i++) {
    state1->discard[playerIndex][i] = copper;
  }
  state1->deckCount[playerIndex] = 4;
  for(i = 0; i < 4; i++) {
    state1->deck[playerIndex][i] = copper;
  }
  state1->discard[playerIndex][0] = gardens;
  int result1 = scoreFor(playerIndex, state1);
  int score = 1;
  checkIntEquals(score, result1, "scoreFor: score for gardens in discard pile");
}

void testDeckCardScore(int card, int score) {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 0;
  state1->discardCount[playerIndex] = 0;
  state1->deckCount[playerIndex] = 1;
  state1->deck[playerIndex][0] = card;
  int result1 = scoreFor(playerIndex, state1);
  printf("Checking score for card type %d\n", card);
  checkIntEquals(score, result1, "scoreFor: score for card in deck pile");
}
void testDeckGardenScore() {
  struct gameState* state1 = malloc(sizeof(struct gameState));
  int playerIndex = 0;
  state1->handCount[playerIndex] = 4;
  int i;
  for(i = 0; i < 4; i++) {
    state1->hand[playerIndex][i] = copper;
  }
  state1->discardCount[playerIndex] = 4;
  for(i = 0; i < 4; i++) {
    state1->discard[playerIndex][i] = copper;
  }
  state1->deckCount[playerIndex] = 4;
  for(i = 0; i < 4; i++) {
    state1->deck[playerIndex][i] = copper;
  }
  state1->deck[playerIndex][0] = gardens;
  int result1 = scoreFor(playerIndex, state1);
  int score = 1;
  checkIntEquals(score, result1, "scoreFor: score for gardens in deck pile");
}
int main() {
  testHandCardScore(curse, -1);
  testHandCardScore(estate, 1);
  testHandCardScore(duchy, 3);
  testHandCardScore(province, 6);
  testHandCardScore(great_hall, 1);
  testHandGardenScore();
  
  testDiscardCardScore(curse, -1);
  testDiscardCardScore(estate, 1);
  testDiscardCardScore(duchy, 3);
  testDiscardCardScore(province, 6);
  testDiscardCardScore(great_hall, 1);
  testDiscardGardenScore();
  
  testDeckCardScore(curse, -1);
  testDeckCardScore(estate, 1);
  testDeckCardScore(duchy, 3);
  testDeckCardScore(province, 6);
  testDeckCardScore(great_hall, 1);
  testDeckGardenScore();
  
  if (!anyFailed) {
    printf("TEST SUCCESSFULLY COMPLETED\n");
  } else {
    printf("TEST FAILED\n");
  }
}
