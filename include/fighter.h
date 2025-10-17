#ifndef FIGHTER_H
#define FIGHTER_H

typedef enum {
  NONE,
  Red,
  Blue,
  Draw
} Side;

typedef struct {
  int health;
  int stamina;
  int speed;
  int strength;
  int defense;
} Fighter;


Fighter initFighter();

#endif
