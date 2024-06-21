#include "game.h"
int money = 100;//0
int Playerlife = 5;
int stage = 1;
int storelevel = 1;
int select = 0;
int shuffle = 2; // Ȧ���� ���� �ƴϸ� �󸮱�
int upgradeShopDiscount = 0;

int pigCount = 0;

struct unit shop[SHOP_SIZE];
struct unit team[TEAM_SIZE];
struct unit enemy[TEAM_SIZE];
struct unit fightteam[TEAM_SIZE];

void game_init()
{
	money += 10;

	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_TOP);
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	// insert backgroundimage
	
	if(shuffle / 2 == 1)
		summonshop();
}

void game_update()
{
	//work mode
	CP_Settings_TextSize(20.0f);
	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "Mousepointpos: %f, %f", CP_Input_GetMouseX(), CP_Input_GetMouseY());
	CP_Font_DrawText(buffer, 30, 30);

	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

	for (int i = 0; i < 3; i++)
	{
		if (triggeredrect(200.0f + 250 * (i), 600, 250, 200) && shop[i].type != 0)
		{
			select = i+1;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (triggeredrect(200.0f + 250 * (i), 300, 250, 200) && team[i].type != 0)
		{
			select = i + 4;
		}
	}


	//When you release the click
	if (select != 0)
	{

		if (select >= 4)
		{
			drawsellinterface();
		}
		if (CP_Input_MouseReleased(MOUSE_BUTTON_1))
		{
			float x = CP_Input_GetMouseX();
			float y = CP_Input_GetMouseY();
			
			if (select >= 4)
			{
				//if mousepointer sell -> sell
				if (checksell() == 1)
				{
					money += 1;

					if (team[select - 4].type == hamster)
						SellHamster();
					else if (team[select - 4].type == pig)
						pigCount--;
					team[select - 4].type = 0;
				}

				if (300 <= y && y <= 500) {
					Callswap(select - 4, (int)(x-200)/250,4);
				}
			}
			else//Drop from shop
			{
				if (300 <= y && y <= 500 && 3 <= money)
				{
					BuyUnit(select - 1, ((int)x - 200) / 250, 3, 4);
				}
			}
			select = 0;
		}
		
	}
		//Add to our team
		// set the shop selected slot as  empty
		// selected = 0
	DrawTeam();
	Drawinterfaces(money, Playerlife, stage);
	drawendturn();
	drawfreeze();
	drawrefresh();
	drawupgradestore();
	
	DrawShop();
	
	if (isrefreshclicked() == 1)
	{
		summonshop();
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
		ActivatePig();

		money = 0;
		CP_Engine_SetNextGameState(stage_init, stage_update, stage_exit);
		CP_Engine_Run();
	}
}

void game_exit() 
{

}

void Callswap(int myId, int otherId, int size)
{
	struct unit u;
	
	if (myId < size && myId >= 0 && otherId >= 0 && otherId < size)
	{
		u = team[myId];
		team[myId] = team[otherId];
		team[otherId] = u;
	}
}

void BuyUnit(int shopID, int teamID, int sizeshop, int sizeteam)
{
	if ((shopID < 0 || shopID >= sizeshop) || (teamID < 0 || teamID >= sizeteam))
		return;

	switch (shop[shopID].type)
	{
	case spider:
		BuySpider(shopID, teamID);
		break;

	case hamster:
		// �� �� effect
		break;

	case sparrow:
		upgradeShopDiscount--;
		break;	
		
	case pigeon:
		break;

	case frog:
		BuyFrog(shopID);
		break;

	case chicken:
		BuyChicken(teamID);
		break;

	case cheerleader:
		BuyCheerleader();
		break;

	case pig:
		pigCount++;
		break;

	case tiger:
		break;

	case chameleon:
		BuyChameleon(shopID, teamID);
		break;
	case dog:
		dogskill(shopID);
	//default:
	//	return;
	}

	money -= 3;
	//money -= shop[shopID].price;

	if (shop[shopID].type != chameleon)
		team[teamID] = shop[shopID];
	shop[shopID].type = 0;
}

void BuySpider(int shopID, int teamID)
{
	int i;

	// ���� ��� ����
	int stock = 0;
	for (i = 0; i < SHOP_SIZE; i++)
	{
		if (shop[i].type != 0)
			stock++;
	}

	// ������ spider�� �ִ� ��� (����� unit�� ����)
	if (stock == 1)
		return;

	// ���� unit �� �������� �ϳ� �����Ͽ� att, life ���
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

	// ����� unit ����
	shop[randShopID].type = 0;
}

void BuyFrog(int shopID)
{
	// stage��ŭ att, life�� ������
	shop[shopID].att += stage;
	shop[shopID].life += stage;
}

void SellHamster()
{
	int i, sellID = select - 4;

	// team ���� �ο�
	int teamNum = 0;
	for (i = 0; i < TEAM_SIZE; i++)
	{
		if (team[i].type != 0)
			teamNum++;
	}

	// team�� hamster�� �ִ� ��� (�ٸ� team unit ����)
	if (teamNum == 1)
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

void BuyCheerleader()
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

void BuyChicken(int teamID)
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		if (i != teamID && team[i].type == 0)
		{
			team[i].type = 9;
			LoadUnitFromFile(&team[i]);
			return;
		}
	}
}

void ActivatePig()
{
	if (pigCount >= 0 && money > 0)
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

void BuyChameleon(int shopID, int teamID)
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
		team[teamID] = team[maxIdx];
	else
		team[teamID] = shop[shopID];
}

void dogskill(int shopID)
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
