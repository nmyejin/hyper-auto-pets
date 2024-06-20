#include "game.h"
int money = 10;
int Playerlife = 5;
int stage = 1;
int storelevel = 1;
int select;
int shuffle = 1; // 홀수면 섞고 아니면 얼리기

struct unit shop[3];
struct unit team[4];
struct unit enemy[4];
struct unit fightteam[4];

void game_init()
{
	money = 100;

	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_TOP);
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 0));
	// insert backgroundimage
	
	if(shuffle % 2 == 1)
		summonshop();
}
void game_update()
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	
	if (triggeredrect(200, 600, 250, 200) && shop[0].type != 0) //slot1
	{
		select = 1;
	}
	else if (triggeredrect(450, 600, 250, 200) && shop[1].type != 0) //slot2
	{
		select = 2;
	}
	else if (triggeredrect(700, 600, 250, 200) && shop[2].type != 0) //slot3
	{
		select = 3;
	}



	//When you release the click
	if (CP_Input_MouseReleased(MOUSE_BUTTON_1) && select != 0)
	{
		float x = CP_Input_GetMouseX();
		float y = CP_Input_GetMouseY();
		if (300 <= y && y <= 500 && 3 <= money)
		{
			if (200 <= x && x < 450)
			{
				team[0] = shop[select - 1];
				money -= 3;
				shop[select - 1].type = 0;
			}
			if (450 <= x && x < 700)
			{
				team[1] = shop[select - 1];
				money -= 3;
				shop[select - 1].type = 0;
			}
			if (700 <= x && x < 950)
			{
				team[2] = shop[select - 1];
				money -= 3;
				shop[select - 1].type = 0;
			}
			if (950 <= x && x < 1200)
			{
				team[3] = shop[select - 1];
				money -= 3;
				shop[select - 1].type = 0;
			}
		}		
		select = 0;
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

	shuffle = 1;
	
	if (isrefreshclicked() == 1)
	{
		summonshop();
		money -= 1;
	}

	if (isfreezeclicked() == 1)
	{
		shuffle += 1;
	}

	if (isendturnclicked() == 1)
	{
		CP_Engine_SetNextGameState(stage_init, stage_update, stage_exit);
		CP_Engine_Run();
	}
}
void game_exit() 
{

}
