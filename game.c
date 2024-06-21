#include "game.h"
int money = 1000;//0
int Playerlife = 5;
int stage = 1;
int storelevel = 1;
int select = 0;
int shuffle = 2; // 홀수면 섞고 아니면 얼리기

struct unit shop[3];
struct unit team[4];
struct unit enemy[4];
struct unit fightteam[4];

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
	//좌표
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

	if (isendturnclicked() == 1)
	{
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
		// 팔 때 effect
		break;

	case pigeon:
		break;

	case sparrow:
		break;

	case frog:
		BuyFrog(shopID);
		break;
	case dog:
		dogskill(shopID);
	//default:
	//	return;
	}

	money -= 3;
	//money -= shop[shopID].price;
	team[teamID] = shop[shopID];
	shop[shopID].type = 0;
}

void BuySpider(int shopID, int teamID)
{
	int i;

	// 상점 재고 개수
	int stock = 0;
	for (i = 0; i < SHOP_SIZE; i++)
	{
		if (shop[i].type != 0)
			stock++;
	}

	// 상점에 spider만 있는 경우 (흡수할 unit이 없음)
	if (stock == 1)
		return;

	// 상점 unit 중 랜덤으로 하나 선택하여 att, life 흡수
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
}

void BuyFrog(int shopID)
{
	// stage만큼 att, life에 더해짐
	shop[shopID].att += stage;
	shop[shopID].life += stage;
}

void SellHamster()
{
	int i, sellID = select - 4;

	// team 남은 인원
	int teamNum = 0;
	for (i = 0; i < TEAM_SIZE; i++)
	{
		if (team[i].type != 0)
			teamNum++;
	}

	// team에 hamster만 있는 경우 (다른 team unit 없음)
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
