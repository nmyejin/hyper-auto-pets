#pragma once
#include "cprocessing.h"
#include "game.h"
#include "shop.h"
#include <stdio.h>
#include "unit.h"

#define PI 3.14159226535897932

extern float upperBarHeight;
extern float cardWidth, cardHeight;
extern float btnWidth, btnHeight;

extern float stagePosX, stagePosY;
extern float teamPosX, teamPosY;
extern float shopPosX, shopPosY;
extern float lowerBtnPosX, lowerBtnPosY;

void DrawInterface(int howmuchmoney, int howmanylife, int stage);

void DrawStage(float x, float y);
void DrawMoney(float x, float y);
void DrawLife(float x, float y);
void DrawSellButton();

void Drawunit(struct unit store_unit, float x, float y);
void Drawunittext(float posx, float posy, int type);

void DrawShop();
void DrawTeam();
//void drawfreeze();
//void drawendturn();
//void drawrefresh();
void drawupgradestore();


void ShowUnitDescription(struct unit* unit);

//combat
void drawunitlife(int life, float unitx, float unity);
void drawunitatt(int att, float unitx, float unity);
void drawfightteam(struct unit* abc, float x, float y, int enemyT);
void combat_interface(); 
int checksell();
