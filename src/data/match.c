#include <stdbool.h>
#include "match.h"
#include "fighter.h"

Match createMatch(Fighter blue, Fighter red) {
  Match newMatch = {
    winner: NONE,
    turn: 0,
    blue: blue,
    red: red
  };
  return newMatch;
};

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
