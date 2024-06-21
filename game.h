#pragma once
#include "clickobject.h"
#include "cprocessing.h"
#include "drawunit.h"
#include "shop.h"
#include "unit.h"
#include "stage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SHOP_SIZE 3
#define TEAM_SIZE 4

void game_init(void);
void game_update(void);
void game_exit(void);


void summonshop();
int checkstorelist(int sl);
//void Drawspidertext(float posx, float posy);
void Drawunittext(float posx, float posy, int type);
void Callswap(int myId, int otherId, int size); 
void BuyUnit(int shopID, int teamID, int sizeshop, int sizeteam);

void SellHamster();
void BuySpider(int shopID, int teamID);
void BuyFrog(int shopID);
void dogskill(int shopID);
void BuyCheerleader();
void BuyChicken(int teamID);
void ActivatePig();
void BuyChameleon(int teamIdx);

extern int money;
extern int Playerlife;
extern int stage;
extern int storelevel;
extern int select;
extern int upgradeShopDiscount;

extern struct unit shop[SHOP_SIZE];
extern struct unit team[TEAM_SIZE];
extern struct unit enemy[4];
extern struct unit fightteam[4];