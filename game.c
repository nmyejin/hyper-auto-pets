#include "game.h"
int money = 110;//0
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
	//work mode
	CP_Settings_TextSize(20.0f);
	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "Mousepointpos: %f, %f", CP_Input_GetMouseX(), CP_Input_GetMouseY());
	CP_Font_DrawText(buffer, 30, 30);

	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	
	if (triggeredrect(200, 600, 250, 200) && shop[0].type != 0) //slot1
	{
		select = 1;//store1
	}
	else if (triggeredrect(450, 600, 250, 200) && shop[1].type != 0) //slot2
	{
		select = 2;//store2
	}
	else if (triggeredrect(700, 600, 250, 200) && shop[2].type != 0) //slot3
	{
		select = 3;//store3
	}

	if (triggeredrect(200, 300, 250, 200) && team[0].type != 0) //slot1
	{
		select = 4;//team1
	}
	else if (triggeredrect(450, 300, 250, 200) && team[1].type != 0) //slot2
	{
		select = 5;//team2
	}
	else if (triggeredrect(700, 300, 250, 200) && team[2].type != 0) //slot3
	{
		select = 6;//team3
	}
	else if (triggeredrect(950, 300, 250, 200) && team[3].type != 0) //slot3
	{
		select = 7;//team4
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
	if (teamID < sizeteam && shopID < sizeshop && teamID >= 0 && shopID >= 0)
	{
		team[teamID] = shop[shopID];
		money -= 3;
		shop[shopID].type = 0;

		//OnUnitBuy 
	}
}