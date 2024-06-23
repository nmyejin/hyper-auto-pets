#pragma once
#include "cprocessing.h"
#include "game.h"
#include "clickobject.h"

int LastIdxUnitTier(int sl);
void SummonShop(struct unit* shop, int shopLv);

bool IsRefreshClicked();
bool IsFreezeClicked();
bool IsUpgradeClicked();
bool IsEndturnClicked();

void UpgradeShop();