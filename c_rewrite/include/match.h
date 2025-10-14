#ifndef MATCH_H
#define MATCH_H

#include "fighter.h"

typedef struct {
  Side winner;
  int turn;
  Fighter blue;
  Fighter red;
} Match;

Match createMatch(Fighter blue, Fighter red);

#endif
