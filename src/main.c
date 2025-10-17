#include <stdio.h>
#include <raylib.h>
#include "match.h"
#include "combat.h"

typedef struct {
  Match currentMatch;
  float globalTimer;
  float turnTimer;
} GameState;

GameState gameState;

void setCurrentMatch(Match match) {
  gameState.currentMatch = match;
};

void init() {
  InitWindow(1280, 720, "Fight Sim");
  Match currentMatch = createMatch(initFighter(), initFighter());
  setCurrentMatch(currentMatch);

  // more testing stuff here:
  // Fighter *fighter1 = &currentMatch.blue;
  // Fighter *fighter2 = &currentMatch.red; 
  gameState.currentMatch.actionBlue.type = HighAttack;
  gameState.currentMatch.actionRed.type = HighDefend;
}

void draw() {
  // delete later just for testing bruh
  ClearBackground(GRAY);
  char blueHealth[32];
  char redHealth[32];
  char turnTimer[32];

  snprintf(blueHealth, sizeof(blueHealth), "Blue Health: %d", gameState.currentMatch.blue.health);
  snprintf(redHealth, sizeof(redHealth), "Red Health: %d", gameState.currentMatch.red.health);
  snprintf(turnTimer, sizeof(turnTimer), "Turn Timer: %.2f", gameState.turnTimer);

  DrawText(blueHealth, 10, 10, 16, WHITE);
  DrawText(redHealth, 10, 30, 16, WHITE);
  DrawText(turnTimer, 10, 50, 16, WHITE);
}

bool shouldContinueTurn() {
  if(gameState.turnTimer >= 2.0) {
    gameState.turnTimer = 0.0;
    return true;
  } else {
    gameState.turnTimer += GetFrameTime();
    return false;
  }
}

void update() {
  // turn logic, too lazy to shove into a function
  if (shouldContinueTurn()) {
    resolveTurn(&gameState.currentMatch);
  }
}

int main(void) {
  init();

  while(!WindowShouldClose()) {
    update();
    BeginDrawing();
    draw();
    EndDrawing();
  }
}
