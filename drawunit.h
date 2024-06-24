#pragma once
#include "cprocessing.h"
#include "game.h"
#include "shop.h"
#include <stdio.h>
#include "unit.h"
#include "combat.h"

extern CP_Image I_Spider;
extern CP_Image I_Hamster;
extern CP_Image I_Pigeon;
extern CP_Image I_Sparrow;
extern CP_Image I_Frog;
extern CP_Image I_Dog;
extern CP_Image I_Turtle;
extern CP_Image I_Chicken;
extern CP_Image I_Chick;
extern CP_Image I_Cheerleader;
extern CP_Image I_PoisonDartFrog;
extern CP_Image I_Owl;
extern CP_Image I_Pig;
extern CP_Image I_Tiger;
extern CP_Image I_Skunk;
extern CP_Image I_Magpie;
extern CP_Image I_Hawk;
extern CP_Image I_Viper;
extern CP_Image I_Elephant;
extern CP_Image I_SnappingTurtle;
extern CP_Image I_Chameleon;

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
void drawupgradestore();


void ShowUnitDescription(struct unit* unit);

//combat
void drawunitlife(int life, float unitx, float unity);
void drawunitatt(int att, float unitx, float unity);
void drawfightteam(struct unit* team, float x, float y, int enemyT);
void combat_interface(); 
int checksell();
void loadimage();
void Imagefree();
