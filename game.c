#include "game.h"

CP_Image backgroundimage2 = NULL;

int money = 0;
int playerLife = 5;
int stage = 1;
int shopLevel = 1;
int select = 0;
bool freeze = 0;

int upgradeShopDiscount = 0;
bool defeatLastCombat = 0;

struct unit shopPlayer[SHOP_SIZE];
struct unit teamPlayer[TEAM_SIZE];
struct unit teamEnemy[TEAM_SIZE];

struct unit fightPlayer[TEAM_SIZE];
struct unit fightEnemy[TEAM_SIZE];

void GameInit()
{
	money += 10;
	moneyEnemy = money;

	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_TOP);
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	backgroundimage2 = CP_Image_Load("./Assets/titleimage.jpg");

	loadimage();
	
	if (!freeze)
		SummonShop(shopPlayer, shopLevel);
	else
		ReloadShopPlayer();
}

void GameUpdate()
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	CP_Image_Draw(backgroundimage2, 1000, 500, 2000, 1000, 255);

	// shop
	for (int i = 0; i < 3; i++)
	{
		if (triggeredrect(shopPosX + cardWidth * i, shopPosY, cardWidth, cardHeight) && shopPlayer[i].type != 0)
			select = i + 1;

		if (shopPlayer[i].type != 0 && MouseHoverRect(shopPosX + cardWidth * i, shopPosY, cardWidth, cardHeight))
			ShowUnitDescription(&shopPlayer[i]);
	}

	// player team
	for (int i = 0; i < 4; i++)
	{
		if (triggeredrect(teamPosX + cardWidth * i, teamPosY, cardWidth, cardHeight) && teamPlayer[i].type != 0)
			select = i + 4;

		if (teamPlayer[i].type != 0 && MouseHoverRect(teamPosX + cardWidth * i, teamPosY, cardWidth, cardHeight))
			ShowUnitDescription(&teamPlayer[i]);
	}

	/* Release click */
	// draw sell button
	if (select >= 4)
		DrawSellButton();

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
				SellUnit(teamPlayer, teamIdx, &money);

			// swap team unit
			if (teamPosY <= y && y <= teamPosY + cardHeight)
				Swap(teamIdx, (int)((x - teamPosX) / cardWidth), 4);
		}
		// shop
		else
		{
			teamIdx = select - 1;

			if (teamPosY <= y && y <= teamPosY + cardHeight)
			{
				BuyUnit(shopPlayer, teamPlayer, teamIdx, (int)((x - teamPosX) / cardWidth), &money);
			}
		}

		select = 0;
	}

	/* Draw */
	DrawInterface(money, playerLife, stage);
	//drawendturn();
	//drawfreeze();
	//drawrefresh();

	DrawTeam();
	DrawShop();
	drawupgradestore();
	
	/* Click Button */
	if (IsRefreshClicked() == 1 && money > 0 && !freeze)
	{
		SummonShop(shopPlayer, shopLevel);
		money -= 1;
	}

	if (IsFreezeClicked() == 1)
	{
		freeze = !freeze;
	}

	if (IsUpgradeClicked() == 1)
	{
		UpgradeShop();
	}

	if (IsEndturnClicked() == 1)
	{
		ActivatePig(teamPlayer, &money);

		money = 0;
		CP_Engine_SetNextGameState(stage_init, stage_update, stage_exit);
		CP_Engine_Run();
	}
}

void GameExit() 
{ 
	Imagefree();
	CP_Image_Free(&backgroundimage2);
}

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

void BuyUnit(struct unit *shop, struct unit *team, int shopID, int teamID, int *gold)
{
	if (*gold < 3
		|| (shopID < 0 || shopID >= SHOP_SIZE) 
		|| (teamID < 0 || teamID >= TEAM_SIZE)
		|| team[teamID].type != 0)
		return;

	// initial setting: buy unit
	bool notBuy = false;

	// effect upon buying unit
	switch (shop[shopID].type)
	{
	case Spider:
		BuySpider(shop, shopID);
		break;

	case Sparrow:
		upgradeShopDiscount--;
		break;

	case Frog:
		BuyFrog(shop, shopID);
		break;

	case Chicken:
		BuyChicken(team, teamID);
		break;

	case Cheerleader:
		BuyCheerleader(team);
		break;

	case Chameleon:
		if (BuyChameleon(team, teamID))
			notBuy = true;
		break;
	}
  
  BuyDog(team, shop, shopID);

	*gold -= 3;

	if (!notBuy)
		team[teamID] = shop[shopID];

	BuyDog(team, shop, shopID);

	shop[shopID].type = 0;
}

void SellUnit(struct unit* team, int teamIdx, int* gold)
{
	(*gold)++;

	if (team[teamIdx].type == Hamster)
		SellHamster(team);
	else if (team[teamIdx].type == Magpie)
		SellMagpie(gold);

	team[teamIdx].type = 0;
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

	team[randTeamID].att += 1;
	team[randTeamID].life += 1;
}

void BuyCheerleader(struct unit* team)
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		if (team[i].type != 0)
		{
			team[i].att += 2;
			team[i].life += 0;
		}
	}
}

void BuyChicken(struct unit* team, int teamID)
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		if (i != teamID && team[i].type == 0)
		{
			/*team[i].type = 9;
			LoadUnitFromFile(&team[i]);*/
			InitializeUnit(&team[i], Chick);
			return;
		}
	}
}

void ActivatePig(struct unit* team, int *gold)
{
	if (*gold > 0)
	{
		for (int i = 0; i < TEAM_SIZE; i++)
		{
			if (team[i].type == Pig)
			{
				team[i].att += 4;
				team[i].life += 4;
			}
		}
	}
}

bool BuyChameleon(struct unit* team, int teamIdx)
{
	int maxIdx = -1;
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

	if (maxIdx != -1)
	{
		team[teamIdx] = team[maxIdx];
		return true;
	}
	else
		return false;
}

void BuyDog(struct unit* team, struct unit* shop, int shopID)
{
	//check dog is exist
	int buffcount = 0;

	for (int i = 0; i < 4; i++)
	{
		if (team[i].type == Dog && shop[shopID].att > team[i].att)
		{
			buffcount++;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int buff = 0;
		if (team[i].type != 0)
		{	
			team[i].att += buff;
		}
	}
}

void SellMagpie(int *gold)
{
	if (defeatLastCombat == 1)
		*gold += 5;
}