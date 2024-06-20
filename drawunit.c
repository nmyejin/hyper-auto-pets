#include "drawunit.h"
#include "math.h"
void Drawunittext(float posx, float posy, int type)
{
	switch (type)
	{
	case spider:
		Drawspidertext(posx, posy);
		break;
	case hamster:
		Drawhamstertext(posx, posy);
		break;
	case pigeon:
		Drawpigeontext(posx, posy);
		break;
	case sparrow:
		Drawsparrowtext(posx, posy);
		break;
	case frog:
		Drawfrogtext(posx, posy);
		break;
	case dog:
		Drawdogtext(posx, posy);
		break;
	case turtle:
		Drawturtletext(posx, posy);
		break;
	case chicken:
		Drawchickentext(posx, posy);
		break;
	case cheerleader:
		Drawcheerleadertext(posx, posy);
		break;
	case poisondart_frog:
		Drawpoisondart_frogtext(posx, posy);
		break;
	case owl:
		Drawowltext(posx, posy);
		break;
	case pig:
		Drawpigtext(posx, posy);
		break;
	case tiger:
		Drawtigertext(posx, posy);
		break;
	case skunk:
		Drawskunktext(posx, posy);
		break;
	case magpie:
		Drawmagpietext(posx, posy);
		break;
	case hawk:
		Drawhawktext(posx, posy);
		break;
	case viper:
		Drawvipertext(posx, posy);
		break;
	case elephant:
		Drawelephanttext(posx, posy);
		break;
	case snapping_turtle:
		Drawsnapping_turtletext(posx, posy);
		break;
	case chameleon:
		Drawchameleontext(posx, posy);
		break;
	}
}

void Drawspidertext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("Spider", x, y);
}
void Drawhamstertext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("hamster", x, y);
}
void Drawpigeontext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("pigeon", x, y);
}
void Drawsparrowtext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("sparrow", x, y);
}
void Drawfrogtext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("frog", x, y);
}
void Drawdogtext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("pigeon", x, y);
}
void Drawturtletext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("turtle", x, y);
}
void Drawcheerleadertext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("cheerleader", x, y);
}
void Drawpoisondart_frogtext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("poisondart_frog", x, y);
}
void Drawowltext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("owl", x, y);
}
void Drawpigtext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("pig", x, y);
}
void Drawtigertext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("tiger", x, y);
}
void Drawskunktext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("skunk", x, y);
}
void Drawmagpietext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("magpie", x, y);
}
void Drawchickentext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("chicken", x, y);
}
void Drawhawktext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("hawk", x, y);
}
void Drawvipertext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("viper", x, y);
}
void Drawelephanttext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("elephant", x, y);
}
void Drawchameleontext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("chameleon", x, y);
}
void Drawsnapping_turtletext(float posx, float posy)
{
	float x = posx;
	float y = posy;
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(100.0f);
	CP_Font_DrawText("snapping_turtle", x, y);
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
	if(team[0].type == 0)
		CP_Graphics_DrawRect(200, 300, 250, 200); //deckslot1
	if (team[1].type == 0)
		CP_Graphics_DrawRect(450, 300, 250, 200); //deckslot2
	if (team[2].type == 0)
		CP_Graphics_DrawRect(700, 300, 250, 200); //deckslot3
	if (team[3].type == 0)
		CP_Graphics_DrawRect(950, 300, 250, 200); //deckslot1

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(200, 600, 250, 200); // storeslot1
	CP_Graphics_DrawRect(450, 600, 250, 200); // storeslot1
	CP_Graphics_DrawRect(700, 600, 250, 200); // storeslot1

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 0));
	CP_Graphics_DrawRect(1200, 800, 300, 200); // refresh store
	CP_Graphics_DrawRect(1525, 800, 200, 200); // freeze store
	CP_Graphics_DrawRect(1750, 800, 200, 200); // endturn
}



void Drawunit(struct unit store_unit, float x, float y)
{
	if (store_unit.type <= 0)
		return;
	else if (store_unit.type <= frog)
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	else if (store_unit.type <= cheerleader)
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	else if (store_unit.type <= magpie)
		CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	else if (store_unit.type <= chameleon)
		CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));


	CP_Graphics_DrawRect(x, y, 250, 200);

	if (store_unit.type < spider || chameleon < store_unit.type)
	{
		return;
	}

	drawunitlife(store_unit.life, x, y);
	drawunitatt(store_unit.att, x, y);
	//DrawATT

	switch (store_unit.type)
	{
	case spider:
		Drawunittext(x, y, spider);
		break;
	case hamster:
		Drawunittext(x, y, hamster);
		break;
	case pigeon:
		Drawunittext(x, y, pigeon);
		break;
	case sparrow:
		Drawunittext(x, y, sparrow);
		break;
	case frog:
		Drawunittext(x, y, frog);
		break;
	case dog:
		Drawunittext(x, y, dog);
		break;
	case turtle:
		Drawunittext(x, y, turtle);
		break;
	case chicken:
		Drawunittext(x, y, chicken);
		break;
	case cheerleader:
		Drawunittext(x, y, cheerleader);
		break;
	case poisondart_frog:
		Drawunittext(x, y, poisondart_frog);
		break;
	case owl:
		Drawunittext(x, y, owl);
		break;
	case pig:
		Drawunittext(x, y, pig);
		break;
	case tiger:
		Drawunittext(x, y, tiger);
		break;
	case skunk:
		Drawunittext(x, y, skunk);
		break;
	case magpie:
		Drawunittext(x, y, magpie);
		break;
	case hawk:
		Drawunittext(x, y, hawk);
		break;
	case viper:
		Drawunittext(x, y, viper);
		break;
	case elephant:
		Drawunittext(x, y, elephant);
		break;
	case snapping_turtle:
		Drawunittext(x, y, snapping_turtle);
		break;
	case chameleon:
		Drawunittext(x, y, chameleon);
		break;
	default:
		break;
	}
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
		Drawunit(shop[i-1], x, y);
	}
}
void DrawTeam()
{
	for (int i = 1; i < 5; i++)
	{
		float x = 200.0f + 250 * (i - 1);
		float y = 300;
		Drawunit(team[i - 1], x, y);
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

#define PI 3.14159226535897932

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
		sprintf_s(buffer, 100, "%i t: %3.2f %3.2f e: %3.2f %3.2f\n", i, team[i].time, team[i].Maxtime, enemy[i].time, enemy[i].Maxtime);
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