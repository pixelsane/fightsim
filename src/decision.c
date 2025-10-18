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

Action decideAction(PrimaryDecisionOdds pOdds) {
  Action finalDecision;
  ActionTriad primaryDecision = generatePrimaryDecision(pOdds);

  if(primaryDecision == Attack) {
    // actual shit: decideAttack()
    finalDecision.type = HighAttack;
    finalDecision.staminaCost = 5;
  } else if(primaryDecision == Defend) {
    finalDecision.type = HighDefend;
    finalDecision.staminaCost = 0;
  }
  return finalDecision;
}

void generateActions(Match *match) {
  // this should be dynamic soon
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
