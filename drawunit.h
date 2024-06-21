#pragma once
#include "cprocessing.h"
#include "game.h"
#include <stdio.h>
#include "unit.h"

void Drawunittext(float posx, float posy, int type);
void Drawspidertext(float posx, float posy);
void Drawhamstertext(float posx, float posy);
void Drawpigeontext(float posx, float posy);
void Drawsparrowtext(float posx, float posy);
void Drawfrogtext(float posx, float posy);
void Drawdogtext(float posx, float posy);
void Drawturtletext(float posx, float posy);
void Drawcheerleadertext(float posx, float posy);
void Drawpoisondart_frogtext(float posx, float posy);
void Drawowltext(float posx, float posy);
void Drawpigtext(float posx, float posy);
void Drawtigertext(float posx, float posy);
void Drawskunktext(float posx, float posy);
void Drawmagpietext(float posx, float posy);
void Drawchickentext(float posx, float posy);
void Drawhawktext(float posx, float posy);
void Drawvipertext(float posx, float posy);
void Drawelephanttext(float posx, float posy);
void Drawchameleontext(float posx, float posy);
void Drawsnapping_turtletext(float posx, float posy);
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
