#include "game.h"

int money = 100;
int playerLife = 5;
int stage = 1;
int storelevel = 1;
int select = 0;

int upgradeShopDiscount = 0;
bool defeatLastCombat = 0;

int shuffle = 2;

struct unit shopPlayer[SHOP_SIZE];
struct unit teamPlayer[TEAM_SIZE];
struct unit teamEnemy[TEAM_SIZE];
struct unit fightteam[TEAM_SIZE];

void GameInit()
{
	money += 10;

	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_TOP);
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	// insert backgroundimage
	
	if(shuffle / 2 == 1)
		SummonShop();
}

void GameUpdate()
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "Mousepointpos: %f, %f", CP_Input_GetMouseX(), CP_Input_GetMouseY());
	CP_Settings_TextSize(20.0f);
	CP_Font_DrawText(buffer, 30, 30);

	/* Input mouse */
	// shop
	for (int i = 0; i < 3; i++)
	{
		if (triggeredrect(200.0f + 250 * i, 600, 250, 200) && shopPlayer[i].type != 0)
		{
			select = i + 1;
		}
	}

	// player team
	for (int i = 0; i < 4; i++)
	{
		if (triggeredrect(200.0f + 250 * i, 300, 250, 200) && teamPlayer[i].type != 0)
		{
			select = i + 4;
		}
	}

	/* Release click */
	// draw sell button
	if (select >= 4)
	{
		drawsellinterface();
	}

	if (CP_Input_MouseReleased(MOUSE_BUTTON_1))
	{
		float x = CP_Input_GetMouseX();
		float y = CP_Input_GetMouseY();
		int teamIdx;

		// player team
		if (select >= 4)
		{
			teamIdx = select - 4;

			// sell team unit
			if (checksell() == 1)
			{
				money += 1;

				if (teamPlayer[teamIdx].type == hamster)
					SellHamster(teamPlayer);
				else if (teamPlayer[teamIdx].type == magpie)
					SellMagpie();
				teamPlayer[teamIdx].type = 0;
			}

			// swap team unit
			if (300 <= y && y <= 500) {
				Swap(teamIdx, (int)(x - 200) / 250, 4);
			}
		}
		// shop
		else
		{
			teamIdx = select - 1;

			if (300 <= y && y <= 500 && 3 <= money)
			{
				BuyUnit(shopPlayer, teamPlayer, select - 1, ((int)x - 200) / 250);
			}
		}

		select = 0;
	}

	/* Draw */
	Drawinterfaces(money, playerLife, stage);
	DrawTeam();
	DrawShop();

	drawendturn();
	drawfreeze();
	drawrefresh();
	drawupgradestore();
	
	/* Click Button */
	if (isrefreshclicked() == 1 && money > 0)
	{
		SummonShop();
		money -= 1;
	}

	if (isfreezeclicked() == 1)
	{
		if (shuffle == 2)
			shuffle += 2;
		else if (shuffle == 4)
			shuffle -= 2;
	}

	if (isupgradeclicked() == 1)
	{
		UpgradeShop();
	}

	if (isendturnclicked() == 1)
	{
		ActivatePig(teamPlayer);

		money = 0;
		CP_Engine_SetNextGameState(stage_init, stage_update, stage_exit);
		CP_Engine_Run();
	}
}

void GameExit() { }

void Swap(int myId, int otherId, int size)
{
	struct unit u;
	
	if (myId < size && myId >= 0 && otherId >= 0 && otherId < size)
	{
		u = teamPlayer[myId];
		teamPlayer[myId] = teamPlayer[otherId];
		teamPlayer[otherId] = u;
	}
}

void BuyUnit(struct unit *shop, struct unit *team, int shopID, int teamID)
{
	if ((shopID < 0 || shopID >= SHOP_SIZE) || (teamID < 0 || teamID >= TEAM_SIZE))
		return;

	switch (shop[shopID].type)
	{
	case spider:
		BuySpider(shop, shopID);
		break;

	case sparrow:
		upgradeShopDiscount--;
		break;

	case frog:
		BuyFrog(shop, shopID);
		break;

	case chicken:
		BuyChicken(team, teamID);
		break;

	case cheerleader:
		BuyCheerleader(team);
		break;

	case chameleon:
		BuyChameleon(team, teamID);
		break;

	case dog:
		BuyDog(team, shop, shopID);
	}

	money -= 3;

	if (shop[shopID].type != chameleon)
		team[teamID] = shop[shopID];
	shop[shopID].type = 0;
}

void BuySpider(struct unit* shop, int shopID)
{
	// unit num in shop inventory
	int num = 0;
	for (int i = 0; i < SHOP_SIZE; i++)
	{
		if (shop[i].type != 0)
			num++;
	}

	// spider only in shop inventory
	if (num == 1)
		return;

	// absorb random unit from shop inventory
	srand((unsigned int)time(NULL));
	int randShopID = shopID + (rand() % (SHOP_SIZE - 1)) + 1;
	if (randShopID >= SHOP_SIZE)
		randShopID -= SHOP_SIZE;

	while (randShopID == shopID || shop[randShopID].type == 0)
	{
		randShopID++;

		if (randShopID >= SHOP_SIZE)
			randShopID = 0;
	}

	shop[shopID].att += shop[randShopID].att;
	shop[shopID].life += shop[randShopID].life;

	shop[randShopID].type = 0;
}

void BuyFrog(struct unit* shop, int shopID)
{
	// add stage level
	shop[shopID].att += stage;
	shop[shopID].life += stage;
}

void SellHamster(struct unit *team)
{
	int i, sellID = select - 4;

	// unit num in team inventory
	int num = 0;
	for (i = 0; i < TEAM_SIZE; i++)
	{
		if (team[i].type != 0)
			num++;
	}

	// hamster only in team inventory
	if (num == 1)
		return;

	srand((unsigned int)time(NULL));
	int randTeamID = sellID + (rand() % (TEAM_SIZE - 1)) + 1;
	if (randTeamID >= TEAM_SIZE)
		randTeamID -= TEAM_SIZE;

	while (randTeamID == sellID || team[randTeamID].type == 0)
	{
		randTeamID++;

		if (randTeamID >= TEAM_SIZE)
			randTeamID = 0;
	}

	team[randTeamID].att += 2;
	team[randTeamID].life += 2;
}

void BuyCheerleader(struct unit* team)
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		if (team[i].type != 0)
		{
			team[i].att += 2;
			team[i].life += 2;
		}
	}
}

void BuyChicken(struct unit* team, int teamID)
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		if (i != teamID && teamPlayer[i].type == 0)
		{
			teamPlayer[i].type = 9;
			LoadUnitFromFile(&teamPlayer[i]);
			return;
		}
	}
}

void ActivatePig(struct unit* team)
{
	if (money > 0)
	{
		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (team[i].type == pig)
			{
				team[i].att += 4;
				team[i].life += 4;
			}
		}
	}
}

void BuyChameleon(struct unit* team, int teamIdx)
{
	int maxIdx = teamIdx;
	int maxValue = 0;

	for (int i = 0; i < TEAM_SIZE; i++)
	{
		if (team[i].type == 0)
			continue;

		int value = team[i].att + team[i].life;
		if (value > maxValue)
		{
			maxIdx = i;
			maxValue = value;
		}
	}

	team[teamIdx] = team[maxIdx];
}

void BuyDog(struct unit* team, struct unit* shop, int shopID)
{
	//check dog is exist
	int buff = 0;

	for (int i = 0; i < 4; i++)
	{
		if (team[i].type == 6 && shop[shopID].att > team[i].att)
		{
			buff++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (team[i].type != 0)
		{	
			while (buff > 0)
			{
				team[i].att++;
				buff--;
			}
		}
	}
}

void SellMagpie()
{
	if (defeatLastCombat == 1)
		money += 5;
}