#include "shop.h"

int shopInfo[5][5] = {	// cost, rate(unit A, B, C, D)
	{ 0,100,  0,  0,  0},
	{10, 50, 50,  0,  0},
	{15, 25, 50, 25,  0},
	{25, 15, 40, 40,  5},
	//{30, 10, 35, 45, 10}
	{30, 0, 0, 0, 100}
};

int LastIdxUnitTier(int sl)
{
	if (sl == 1)
		return frog;
	if (sl == 2)
		return cheerleader;
	if (sl == 3)
		return magpie;
	if (sl == 4)
		return chameleon;
	return 0;
}
void SummonShop(struct unit *shop)
{
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < SHOP_SIZE; i++)
	{
		int randNum = rand() % 100;
		int threshold = 0;

		for (int j = 0; j < 4; j++)	// ���� ����
		{
			threshold += shopInfo[storelevel - 1][j + 1];

			if (randNum < threshold)
			{
				int storeUnit = -1;
				if (j == 0)
					storeUnit = CP_Random_RangeInt(1, LastIdxUnitTier(j + 1));
				else
				{
					do
					{
						storeUnit = CP_Random_RangeInt(1 + LastIdxUnitTier(j), LastIdxUnitTier(j + 1));
					} while (storeUnit == 9);

				}
				
				shop[i].type = storeUnit;
				LoadUnitFromFile(&shop[i]);
				break;
			}
		}
	}
}

int isrefreshclicked()
{
	if (clickedrect(1200, 800, 300, 200) == 1)
		return 1;
	return 0;
}

int isfreezeclicked()
{
	if (clickedrect(1525, 800, 200, 200) == 1)
		return 1;	
	return 0;
}

int isupgradeclicked()
{
	if (clickedrect(200, 840, 250, 100) == 1)
		return 1;
	return 0;
}

int isendturnclicked()
{
	if (clickedrect(1750, 800, 200, 200) == 1)
		return 1;
	return 0;
}

void UpgradeShop()
{
	int cost = shopInfo[storelevel][0] + upgradeShopDiscount;
	if (storelevel < 5 && money >= cost)
	{
		money -= cost;
		storelevel++;
	}
}