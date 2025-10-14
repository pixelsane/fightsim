#include "fighter.h"
#include <stdlib.h>
#include <time.h>

float speed_max = 5;
float strength_max = 5;
float defense_max = 5;

Fighter initFighter() {
  Fighter newFighter = {
    health: 100,
    focus: 50
  };

  newFighter.speed = (float)rand() / speed_max;
  newFighter.strength = (float)rand() / strength_max;
  newFighter.defense = (float)rand() / defense_max;
  return newFighter;
};
