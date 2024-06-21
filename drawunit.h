#pragma once
#include "cprocessing.h"
#include "game.h"
#include <stdio.h>
#include "unit.h"

void Drawunittext(float posx, float posy, int type);
void Drawmoney(int howmuch);
void Drawinterfaces(int howmuchmoney, int howmanylife, int stage);
void Drawunit(struct unit store_unit, float x, float y);
void Drawlife(int howmanylife);
void Drawstage(int stage);
void DrawShop();
void DrawTeam();
void drawfreeze();
void drawendturn();
void drawrefresh();
void drawupgradestore();
void drawsellinterface();

//combat
void drawunitlife(int life, float unitx, float unity);
void drawunitatt(int att, float unitx, float unity);
void drawfightteam(struct unit* abc, float x, float y, int enemyT);
void combat_interface(); 
int checksell();
