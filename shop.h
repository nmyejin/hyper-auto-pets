#pragma once
#include "cprocessing.h"
#include "game.h"
#include "clickobject.h"

#define MAX_SHOP_LEVEL 5
#define MAX_UNIT_TIER 4

int LastIdxUnitTier(int sl);
void SummonShop(struct unit* shop);

bool IsRefreshClicked();
bool IsFreezeClicked();
bool IsUpgradeClicked();
bool IsEndturnClicked();

void UpgradeShop();