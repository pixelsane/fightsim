#include <stdio.h>
#include <stdbool.h>
#include "match.h"

void dealDamage(Fighter attacker, Fighter defender, Action actionAttacker, Action actionDefender) {
  int modifier = 1;
  bool defended = 
    (actionAttacker.type == HighAttack && actionDefender.type == HighDefend) || 
    (actionAttacker.type == MidAttack && actionDefender.type == MidDefend) ||
    (actionAttacker.type == LowAttack && actionDefender.type == LowDefend);

  if (defended) {
    defender.health -= attacker.strength * modifier;
  }
}

void reduceEnergies(Match match) {
  Fighter red = match.red;
  Fighter blue = match.blue;
  Action actionRed = match.actionRed;
  Action actionBlue = match.actionBlue;
  
  red.stamina -= actionRed.staminaCost;
  blue.stamina -= actionBlue.staminaCost;
}

void dealDamages(Match match) {
  Fighter red = match.red;
  Fighter blue = match.blue;
  Action actionRed = match.actionRed;
  Action actionBlue = match.actionBlue;

  dealDamage(red, blue, actionRed, actionBlue);
  dealDamage(blue, red, actionBlue, actionRed);
}

void resolveTurn(Match match) {
  dealDamages(match);
  reduceEnergies(match);
}
