#include <stdio.h>
#include "match.h"

typedef struct {
  Match currentMatch;
} GameState;

GameState gameState;

void setCurrentMatch(Match match) {
  gameState.currentMatch = match;
};

int main(void) {
  Fighter fighter1 = initFighter();
  Fighter fighter2 = initFighter();
  Match currentMatch = createMatch(fighter1, fighter2);

  setCurrentMatch(currentMatch);
  printf("Fighter1 Health: %f\n", fighter1.health);

}
