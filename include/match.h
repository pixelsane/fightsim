#ifndef MATCH_H
#define MATCH_H

#include "fighter.h"

typedef enum {
  Attack,
  Defend,
  Special
} ActionTriad;

typedef enum {
  Wait,
  SpecialAttack,
  SpecialDefend,
  HighAttack, MidAttack, LowAttack,
  HighDefend, MidDefend,LowDefend,
} ActionType;

typedef struct {
  ActionType type;
  int staminaCost;
} Action;

typedef struct {
  Side winner;
  int turn;
  Fighter blue;
  Fighter red;
  Action actionBlue;
  Action actionRed;
} Match;

Match createMatch(Fighter blue, Fighter red);

#endif
