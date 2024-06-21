#include "shop.h"

int checkstorelist(int sl)
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
void summonshop()
{
	for (int i = 0; i < 3; i++)
	{
		int store_unit = CP_Random_RangeInt(1, checkstorelist(storelevel));
		shop[i].type = store_unit;
		LoadUnitFromFile(&shop[i]);
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

int isendturnclicked()
{
	if (clickedrect(1750, 800, 200, 200) == 1)
		return 1;
	return 0;
}