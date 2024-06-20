#pragma once
#include "cprocessing.h"
#include "combat.h"
#include "unit.h"
#include "game.h"

void summonenemyteam(int stage);
void hit();
int checkdead();
void fillin_emptyslot(struct unit* abc, int enemyT);
void CheckHit();
void timer();
int checkcombatover();
void teamintofightteam();