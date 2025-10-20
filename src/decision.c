#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "decision.h"
#include "match.h"

ActionTriad generatePrimaryDecision(PrimaryDecisionOdds pOdds) {
  int max = pOdds.attack + pOdds.defend + pOdds.special;
  int roll = rand() % max;

  if (roll < pOdds.attack) {
      return Attack;
  } else if (roll < pOdds.attack + pOdds.defend) {
      return Defend;
  } else {
      return Special;
  }
}

Action decideAttack() {
  Action action;
  int roll = rand() % 3;
  ActionType attacks[3] = {HighAttack, MidAttack, LowAttack};
  ActionType attackRolled = attacks[roll];
  action.type = attackRolled;
  action.staminaCost = 5; // getStaminaCost()

  return action;
}

Action decideDefend() {
  Action action;
  int roll = rand() % 3;
  ActionType defends[3] = {HighDefend, MidDefend, LowDefend};
  ActionType defendRolled = defends[roll];
  action.type = defendRolled;
  action.staminaCost = 5; // getStaminaCost()

  return action;
}

Action decideAction(PrimaryDecisionOdds pOdds) {
  Action finalDecision;
  ActionTriad primaryDecision = generatePrimaryDecision(pOdds);

  if(primaryDecision == Attack) {
    finalDecision = decideAttack(); // send attack odds later, default is 33%
  } else if(primaryDecision == Defend) {
    finalDecision = decideDefend(); // send defend odds later, default is 33%
  }
  return finalDecision;
}

void generateActions(Match *match) {
  // this should be dynamic soon, should come from tactic cards and coaching modifier stack
  PrimaryDecisionOdds pOdds = {
    attack: 5,
    defend: 5
  };

  // make this generic later
  Action actionBlue = decideAction(pOdds);
  Action actionRed = decideAction(pOdds);

  match->actionBlue = actionBlue;
  match->actionRed = actionRed;
}
