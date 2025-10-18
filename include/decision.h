#ifndef DECISION_H
#define DECISION_H

#include "match.h"

typedef struct {
  int attack;
  int defend;
  int special;
} PrimaryDecisionOdds;


void generateActions(Match *match);

#endif
