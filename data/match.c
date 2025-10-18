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
