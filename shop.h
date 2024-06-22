#pragma once
#include "cprocessing.h"
#include "game.h"
#include "clickobject.h"

int LastIdxUnitTier(int sl);
void SummonShop(struct unit* shop);
int isrefreshclicked();
int isfreezeclicked();
int isupgradeclicked();
int isendturnclicked();

void UpgradeShop();
