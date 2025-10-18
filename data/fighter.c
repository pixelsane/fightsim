#include "fighter.h"
#include <stdlib.h>
#include <time.h>

int speed_max = 5;
int strength_max = 5;
int defense_max = 5;

Fighter initFighter() {
  Fighter newFighter = {
    health: 100,
    stamina: 50
  };

  newFighter.speed = rand() % speed_max;
  newFighter.strength = rand() % strength_max;
  newFighter.defense = rand() % defense_max;
  return newFighter;
};
