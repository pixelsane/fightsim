#ifndef FIGHTER_H
#define FIGHTER_H

typedef enum {
  NONE,
  RED,
  BLUE,
  DRAW
} Side;

typedef struct {
  float health, 
        focus, 
        speed, 
        strength, 
        defense;
} Fighter;

#endif
