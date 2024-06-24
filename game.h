#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "cprocessing.h"

#include "unit.h"
#include "clickobject.h"
#include "drawunit.h"
#include "shop.h"
#include "stage.h"

#define SHOP_SIZE 3
#define TEAM_SIZE 4
#define FINAL_STAGE 10
#define MAX_SHOP_LEVEL 5
#define MAX_UNIT_TIER 4

extern struct unit teamPlayer[TEAM_SIZE];
extern struct unit shopPlayer[SHOP_SIZE];
extern struct unit teamEnemy[TEAM_SIZE];
extern struct unit shopEnemy[SHOP_SIZE];
extern struct unit fightteam[TEAM_SIZE];

extern int money;
extern int moneyEnemy;

extern int playerLife;
extern int stage;
extern int shopLevel;
extern int select;
extern bool freeze;

extern int upgradeShopDiscount;
extern bool defeatLastCombat;

void GameInit(void);
void GameUpdate(void);
void GameExit(void);

void Swap(int myId, int otherId, int size);

void BuyUnit(struct unit* shop, struct unit* team, int shopID, int teamID, int* gold);
void SellUnit(struct unit* team, int teamIdx, int* gold);

void BuySpider(struct unit* shop, int shopID);
void SellHamster(struct unit* team);
void BuyFrog(struct unit* shop, int shopID);

void BuyDog(struct unit* team, struct unit* shop, int shopID);
void BuyChicken(struct unit* team, int teamID);
void BuyCheerleader(struct unit* team);

void ActivatePig(struct unit* team, int* gold);
void SellMagpie(int* gold);

bool BuyChameleon(struct unit* team, int teamIdx);