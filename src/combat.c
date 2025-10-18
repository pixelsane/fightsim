#include <stdio.h>
#include <stdbool.h>
#include "decision.h"
#include "match.h"

bool isAttacking(Action a) {
    return a.type == HighAttack || a.type == MidAttack || a.type == LowAttack;
}

bool isDefending(Action a) {
    return a.type == HighDefend || a.type == MidDefend || a.type == LowDefend;
}

bool isDefended(Action a, Action b) {
    return 
      (a.type == HighAttack && b.type == HighDefend) || 
      (a.type == MidAttack && b.type == MidDefend) ||
      (a.type == LowAttack && b.type == LowDefend);
}

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
  if (!match) return; // JIC, so i wouldn't lose my sanity itf
  generateActions(match);
  resolveAttacks(match);
  //resolveSpecials(match);
  reduceEnergies(match);
}
