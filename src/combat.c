#include <stdio.h>
#include <stdbool.h>
#include "match.h"

void dealDamage(Fighter *attacker, Fighter *defender, Action actionAttacker, Action actionDefender) {
  int modifier = 1;
  bool isWaiting = actionAttacker.type == Wait;

  bool defendSuccess = isDefended(actionAttacker, actionDefender);

  if (!defendSuccess && !isWaiting) {
    defender->health -= attacker->strength * modifier;
  }
}

void reduceEnergies(Match *match) {
  Fighter *red = &match->red;
  Fighter *blue = &match->blue;
  Action actionRed = match->actionRed;
  Action actionBlue = match->actionBlue;

  red->stamina -= actionRed.staminaCost;
  blue->stamina -= actionBlue.staminaCost;
}

void resolveAttacks(Match *match) {
  Fighter *red = &match->red;
  Fighter *blue = &match->blue;
  Action actionRed = match->actionRed;
  Action actionBlue = match->actionBlue;

  if(isAttacking(actionRed)) dealDamage(red, blue, actionRed, actionBlue);
  if(isAttacking(actionBlue)) dealDamage(blue, red, actionBlue, actionRed);
}

void resolveTurn(Match *match) {
  resolveAttacks(match);
  reduceEnergies(match);
}
