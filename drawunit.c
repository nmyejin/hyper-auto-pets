#include "drawunit.h"
#include "math.h"
void Drawunittext(float posx, float posy, int type)
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);

	switch (type)
	{
	case Spider:
		CP_Font_DrawText("Spider", posx, posy);
		break;
	case Hamster:
		CP_Font_DrawText("Hamster", posx, posy);
		break;
	case Pigeon:
		CP_Font_DrawText("Pigeon", posx, posy);
		break;
	case Sparrow:
		CP_Font_DrawText("Sparrow", posx, posy);
		break;
	case Frog:
		CP_Font_DrawText("Frog", posx, posy);
		break;
	case Dog:
		CP_Font_DrawText("Dog", posx, posy);
		break;
	case Turtle:
		CP_Font_DrawText("Turtle", posx, posy);
		break;
	case Chicken:
		CP_Font_DrawText("Chicken", posx, posy);
		break;
	case Chick:
		CP_Font_DrawText("Chick", posx, posy);
		break;
	case Cheerleader:
		CP_Font_DrawText("Cheerleader", posx, posy);
		break;
	case PoisonDartFrog:
		CP_Font_DrawText("Poisonart frog", posx, posy);
		break;
	case Owl:
		CP_Font_DrawText("Owl", posx, posy);
		break;
	case Pig:
		CP_Font_DrawText("Pig", posx, posy);
		break;
	case Tiger:
		CP_Font_DrawText("Tiger", posx, posy);
		break;
	case Skunk:
		CP_Font_DrawText("Skunk", posx, posy);
		break;
	case Magpie:
		CP_Font_DrawText("Magpie", posx, posy);
		break;
	case Hawk:
		CP_Font_DrawText("Hawk", posx, posy);
		break;
	case Viper:
		CP_Font_DrawText("Viper", posx, posy);
		break;
	case Elephant:
		CP_Font_DrawText("Elephant", posx, posy);
		break;
	case SnappingTurtle:
		CP_Font_DrawText("Snapping turtle", posx, posy);
		break;
	case Chameleon:
		CP_Font_DrawText("Chameleon", posx, posy);
		break;
	}
}

void Drawmoney(int howmuchmoney)
{
	char buffer[255] = { 0 };
	sprintf_s(buffer, 255, "%d", howmuchmoney);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Gold:", 0, 0);
	CP_Font_DrawText(buffer, 200, 0);
}
void Drawinterfaces(int howmuchmoney, int howmanylife, int stagewhat)
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(0, 10, 300, 100); //money
	Drawmoney(howmuchmoney);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(310, 10, 300, 100); //life
	Drawlife(howmanylife);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(620, 10, 300, 100); //stage
	Drawstage(stage);

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(200, 300, 250, 200); //deckslot1
	CP_Graphics_DrawRect(450, 300, 250, 200); //deckslot2
	CP_Graphics_DrawRect(700, 300, 250, 200); //deckslot3
	CP_Graphics_DrawRect(950, 300, 250, 200); //deckslot1

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(200, 600, 250, 200); // storeslot1
	CP_Graphics_DrawRect(450, 600, 250, 200); // storeslot1
	CP_Graphics_DrawRect(700, 600, 250, 200); // storeslot1

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect( 200, 840, 250, 100); // upgrade store
	CP_Graphics_DrawRect(1200, 800, 300, 200); // refresh store
	CP_Graphics_DrawRect(1525, 800, 200, 200); // freeze store
	CP_Graphics_DrawRect(1750, 800, 200, 200); // endturn
}



void Drawunit(struct unit store_unit, float x, float y)
{
	if (store_unit.type <= 0
		|| store_unit.type > Chameleon
		|| store_unit.visible == 0)
		return;
	else if (store_unit.type <= Frog)
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	else if (store_unit.type <= Cheerleader)
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	else if (store_unit.type <= Magpie)
		CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	else if (store_unit.type <= Chameleon)
		CP_Settings_Fill(CP_Color_Create(120, 120, 120, 255));

	CP_Graphics_DrawRect(x, y, 250, 200);

	drawunitlife(store_unit.life, x, y);
	drawunitatt(store_unit.att, x, y);
	//DrawATT

	Drawunittext(x, y, store_unit.type);
}
void Drawlife(int howmanylife)
{
	char buffer[255] = { 0 };
	sprintf_s(buffer, 255, "%d", howmanylife);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Life:", 310, 0);
	CP_Font_DrawText(buffer, 510, 0);
}
void Drawstage(int stagewhat)
{
	char buffer[255] = { 0 };
	sprintf_s(buffer, 255, "%d", stagewhat);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Stage:", 620, 0);
	CP_Font_DrawText(buffer, 870, 0);
}
void DrawShop()
{
	for (int i = 1; i < 4; i++)
	{
		float x = 200.0f + 250 * (i - 1);
		float y = 600;

		if (select == i)
		{
			x = CP_Input_GetMouseX() - 125;
			y = CP_Input_GetMouseY() - 100;
		}
		Drawunit(shopPlayer[i-1], x, y);
	}
}
void DrawTeam()
{
	for (int i = 0; i < TEAM_SIZE; i++)
	{
		float x = 200.0f + 250 * (i);
		float y = 300;
		Drawunit(teamPlayer[i], x, y);
	}
}

void drawfreeze()
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(70.0f);
	CP_Font_DrawText("Freeze", 1525, 870);
}
void drawendturn()
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(60.0f);
	CP_Font_DrawText("EndTurn", 1750, 880);
}
void drawrefresh()
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Refresh", 1200, 850);
}
void drawupgradestore()
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Upgrade", 200, 840);
}
//combat
void drawunitlife(int life, float unitx, float unity)
{
	float x = unitx + 240 - 25;
	float y = unity + 180;
	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "%d", life);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(50.0f);
	CP_Font_DrawText(buffer, x, y);
}
void drawunitatt(int att, float unitx, float unity)
{
	float x = unitx + 10;
	float y = unity + 180;
	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "%d", att);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(50.0f);
	CP_Font_DrawText(buffer, x, y);
}

void combat_interface()
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(20.0f);
	CP_Font_DrawText("You", 125, 70);
	CP_Font_DrawText("Enemy", 875, 670);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(125, 100, 250, 200);
	CP_Graphics_DrawRect(375, 100, 250, 200);
	CP_Graphics_DrawRect(625, 100, 250, 200);
	CP_Graphics_DrawRect(875, 100, 250, 200);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(875, 700, 250, 200);
	CP_Graphics_DrawRect(1125, 700, 250, 200);
	CP_Graphics_DrawRect(1375, 700, 250, 200);
	CP_Graphics_DrawRect(1625, 700, 250, 200);
}

void drawfightteam(struct unit* abc, float x, float y, int enemyT)
{
	const float Amplitude = 200.0f;

	for (int i = 1; i < 3; i++)
	{
		float vx = x + 250 * (i);
		float vy = y;
		Drawunit(abc[i], vx, vy);
	}

	for (int i = 0; i < 4; ++i)
	{
		float sx = 30;
		float sy = 30 * (float)i + 40;
		char buffer[100] = { 0 };
		sprintf_s(buffer, 100, "%i t: %3.2f %3.2f e: %3.2f %3.2f\n", i, teamPlayer[i].time, teamPlayer[i].Maxtime, teamEnemy[i].time, teamEnemy[i].Maxtime);
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
		CP_Settings_TextSize(20.0f);
		CP_Font_DrawText(buffer, sx, sy);
	}
	
	
	if (enemyT) //enemy
	{
		//Do up down
		double ratio = abc[0].time / /*abc[0].Maxtime*/1.f;

		float vy = (float)sin( ratio * PI ) * Amplitude;

		Drawunit(abc[0], x, y - vy);
		Drawunit(abc[3], x + 250 * 3, y);
	}
	else //team
	{
		//Do up down
		double ratio = abc[3].time / /* abc[3].Maxtime*/ 1.f;

		float vy = (float)sin(ratio * PI) * Amplitude;

		Drawunit(abc[3], x + 250 * 3, y + vy);
		Drawunit(abc[0], x, y);
	}
}
void drawsellinterface()
{
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 120));
	CP_Graphics_DrawRect(1525, 580, 425, 200);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(170.0f);
	CP_Font_DrawText("  SELL", 1525, 580);
}
int checksell()
{
	if (releasedrect(1525, 580, 425, 200))
	{
		return 1;
	}
	return 0;
}

void ShowUnitDescription(struct unit* unit)
{
	CP_Font_DrawText(unit->description, 1300, 200);
}