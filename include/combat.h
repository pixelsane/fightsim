#ifndef COMBAT_H
#define COMBAT_H

#include "match.h"

void resolveTurn(Match *match);
bool isAttacking(Action a);
bool isDefending(Action a);
bool isDefended(Action a, Action b);

#endif
