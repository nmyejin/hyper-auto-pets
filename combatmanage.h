#pragma once
#include "cprocessing.h"
#include "combat.h"
#include "unit.h"
#include "game.h"
#include "combatmanage.h"
#include "gameover.h"
#include "Windows.h"

extern int result;

void SummonTeamEnemy();
void hit();
void checkdead();
void fillin_emptyslot(struct unit* abc, int enemyT);
void CheckHit();
void timer();
int checkcombatover();
void InitializeTeam();
void givemoneystage(); 
void turtleskill(struct unit* turtle, struct unit* object);
void skunkskill(struct unit* skunk, struct unit* object, int tore);
void owlskill(); 
void poisondartfrogskill(struct unit* object);
void hawkskill(); 
void elephantskill();
void snasnapping_turtleskill();
void viperskill();
int checkgameover();
void ShowResult(int result);

CP_Vector IdxMaxPower(struct unit* arr, int size);
CP_Vector IdxMinPower(struct unit* arr, int size);