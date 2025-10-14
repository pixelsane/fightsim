#include <stdio.h>
#include "match.h"

typedef struct {
  Match currentMatch;
} GameState;

GameState gameState;

void setCurrentMatch(Match match) {
  gameState.currentMatch = match; // consider allocating later if i ever decide to be a lazy person and just mutate the values and add a getter zzz
};

int main(void) {
  Fighter fighter1;
  Fighter fighter2;
  Match currentMatch = createMatch(fighter1, fighter2);

  setCurrentMatch(currentMatch);

}
