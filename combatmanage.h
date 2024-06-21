#pragma once
#include "cprocessing.h"
#include "combat.h"
#include "unit.h"
#include "game.h"
#include "combatmanage.h"
#include "gameover.h"

void summonenemyteam(int stage);
void hit();
void checkdead();
void fillin_emptyslot(struct unit* abc, int enemyT);
void CheckHit();
void timer();
int checkcombatover();
void teamintofightteam();
void givemoneystage(); 
void howmanyturtle();
void turtleskill();
void skunkskill();
void owlskill(); 
void poisondartfrogskill();
void hawkskill(); 
void elephantskill();
void snasnapping_turtleskill();
void viperskill();
int checkgameover();
