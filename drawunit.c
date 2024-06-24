#include "drawunit.h"
#include "math.h"

#define WIDTH 2000
#define HEIGHT 1000

float upperBarHeight = HEIGHT * 0.06f;
float cardWidth = 250, cardHeight = 275;
float btnWidth = 150, btnHeight = 150;

float stagePosX = 20.f, stagePosY = 20.f;
float teamPosX = 140.f, teamPosY = 250.f;
float shopPosX = 140.f + 250, shopPosY = 680.f;
float lowerBtnPosX = 1280.f, lowerBtnPosY = 680.f + 125;

int costShopUpgrade[MAX_SHOP_LEVEL] = { 0, 10, 15, 25, 30 };

CP_Image I_Spider = NULL;
CP_Image I_Hamster = NULL;
CP_Image I_Pigeon = NULL;
CP_Image I_Sparrow = NULL;
CP_Image I_Frog = NULL;
CP_Image I_Dog = NULL;
CP_Image I_Turtle = NULL;
CP_Image I_Chicken = NULL;
CP_Image I_Chick = NULL;
CP_Image I_Cheerleader = NULL;
CP_Image I_PoisonDartFrog = NULL;
CP_Image I_Owl = NULL;
CP_Image I_Pig = NULL;
CP_Image I_Tiger = NULL;
CP_Image I_Skunk = NULL;
CP_Image I_Magpie = NULL;
CP_Image I_Hawk = NULL;
CP_Image I_Viper = NULL;
CP_Image I_Elephant = NULL;
CP_Image I_SnappingTurtle = NULL;
CP_Image I_Chameleon = NULL;
CP_Image Sword = NULL;
CP_Image Heart = NULL;

void DrawInterface(int howmuchmoney, int howmanylife, int stagewhat)
{
	/* Upper Bar */
	CP_Settings_NoStroke();
	float posX = stagePosX;
	float posY = stagePosY;

	// stage
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 180));
	CP_Graphics_DrawRectAdvanced(posX, posY, 250, upperBarHeight, 0.f, 30.f);
	DrawStage(posX, posY);

	// money
	posX += 260;
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 180));
	CP_Graphics_DrawRectAdvanced(posX, posY, 200, upperBarHeight, 0.f, 30.f);
	DrawMoney(posX, posY);

	// life
	posX += 210;
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 180));
	CP_Graphics_DrawRectAdvanced(posX, posY, 330, upperBarHeight, 0.f, 30.f);
	DrawLife(posX, posY);


	/* Slot */
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 130));

	// team
	CP_Settings_NoStroke();
	CP_Graphics_DrawRect(teamPosX - 10, teamPosY - 20, cardWidth * 4 + 20, cardHeight + 30);

	CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 255));
	for (int i = 0; i < 4; i++)
		CP_Graphics_DrawRect(teamPosX + cardWidth * i, teamPosY, cardWidth, cardHeight);

	// shop
	CP_Settings_NoStroke();
	CP_Graphics_DrawRect(teamPosX - 10, shopPosY - 20, cardWidth * 4 + 20, cardHeight + 30);

	CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 255));
	for (int i = 0; i < 3; i++)
		CP_Graphics_DrawRect(shopPosX + cardWidth * i, shopPosY, cardWidth, cardHeight);


	/* Lower Bar */
	posX = lowerBtnPosX;
	posY = lowerBtnPosY;

	CP_Image upgradeImg = CP_Image_Load("./img/upgrade.png");
	CP_Image refreshImg = CP_Image_Load("./img/refresh.png");
	CP_Image freezeImg = CP_Image_Load("./img/freeze_blue.png");
	CP_Image freezeImgNone = CP_Image_Load("./img/freeze_gray.png");
	CP_Image outImg = CP_Image_Load("./img/out.png");

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));

	// upgrade shop button
	CP_Graphics_DrawRect(teamPosX + 40, shopPosY + 125, btnWidth, btnHeight);
	CP_Image_Draw(upgradeImg, teamPosX + 40 + btnWidth / 2, shopPosY + 125 + btnHeight / 2, btnWidth, btnHeight, 255);

	for (int i = 0; i < 3; i++)
	{
		float posX_ = posX + (btnWidth + 10) * i;
		float posY_ = posY;

		if (freeze && i == 1)
			CP_Settings_Fill(CP_Color_Create(158, 195, 255, 255));
		CP_Graphics_DrawRect(posX_, posY_, btnWidth, btnHeight);
		if (freeze && i == 1)
			CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));

		posX_ += btnWidth / 2;
		posY_ += btnHeight / 2;

		switch (i)
		{
		case 0:
			CP_Image_Draw(refreshImg, posX_, posY_, btnWidth, btnHeight, 255);
			break;
		case 1:
			if (freeze)
				CP_Image_Draw(freezeImg, posX_, posY_, btnWidth, btnHeight, 255);
			else
				CP_Image_Draw(freezeImgNone, posX_, posY_, btnWidth, btnHeight, 255);
			break;
		case 2:
			CP_Image_Draw(outImg, posX_, posY_, btnWidth, btnHeight, 255);
		}
	}
}

void DrawStage(float x, float y)
{
	char buffer[50];
	sprintf_s(buffer, 50, "STAGE %d", stage);

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(70.0f);
	CP_Font_DrawText(buffer, x + 20, y - 5);
}

void DrawMoney(float x, float y)
{
	char buffer[10];
	sprintf_s(buffer, 10, "%d", money);

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(70.0f);
	CP_Font_DrawText(buffer, x + 80, y - 5);

	CP_Image img = CP_Image_Load("./img/gold_b.png");
	CP_Image_Draw(img, x + 50, y + 30, upperBarHeight, upperBarHeight, 255);
}

void DrawLife(float x, float y)
{
	CP_Image heartFill = CP_Image_Load("./img/heart_fill.png");
	CP_Image heartEmpty = CP_Image_Load("./img/heart_empty.png");

	int i , j;
	for (i = 0; i < playerLife; i++)
		CP_Image_Draw(heartFill, x + 45 + upperBarHeight * i, y + 30, upperBarHeight - 5, upperBarHeight - 5, 255);

	for (j = i; j < 5; j++)
		CP_Image_Draw(heartEmpty, x + 45 + upperBarHeight * j, y + 30, upperBarHeight - 5, upperBarHeight - 5, 255);
}

void DrawSellButton()
{
	float x = lowerBtnPosX;
	float y = lowerBtnPosY - (btnHeight + 10);
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 120));
	CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 255));
	CP_Graphics_DrawRect(x, y, btnWidth, btnHeight);

	CP_Image img = CP_Image_Load("./img/shop.png");
	CP_Image_Draw(img, x + btnWidth / 2, y + btnHeight / 2, btnWidth, btnHeight, 255);
}

void DrawShop()
{
	for (int i = 1; i < SHOP_SIZE + 1; i++)
	{
		float x = shopPosX + cardWidth * (i - 1);
		float y = shopPosY;

		if (select == i)
		{
			x = CP_Input_GetMouseX() - cardWidth / 2;
			y = CP_Input_GetMouseY() - cardWidth / 2;
		}

		Drawunit(shopPlayer[i - 1], x, y);
	}
}

void DrawTeam()
{
	for (int i = 0; i < TEAM_SIZE; i++)
		Drawunit(teamPlayer[i], teamPosX + cardWidth * i, teamPosY);
}




void loadimage()
{
	Sword = CP_Image_Load("./Assets/Sword.png");
	Heart = CP_Image_Load("./Assets/Heart.png");
	I_Spider = CP_Image_Load("./Assets/spider.png");
	I_Hamster = CP_Image_Load("./Assets/hamster.png");
	I_Pigeon = CP_Image_Load("./Assets/pigeon.png");
	I_Sparrow = CP_Image_Load("./Assets/sparrow.png");
	I_Frog = CP_Image_Load("./Assets/frog.png");
	I_Dog = CP_Image_Load("./Assets/dog.png");
	I_Turtle = CP_Image_Load("./Assets/turtle.png");
	I_Chicken = CP_Image_Load("./Assets/chicken.png");
	I_Chick = CP_Image_Load("./Assets/chick.png");
	I_Cheerleader = CP_Image_Load("./Assets/cheerleader.png");
	I_PoisonDartFrog = CP_Image_Load("./Assets/poisondartfrog.png");
	I_Owl = CP_Image_Load("./Assets/owl.png");
	I_Pig = CP_Image_Load("./Assets/pig.png");
	I_Tiger = CP_Image_Load("./Assets/tiger.png");
	I_Skunk = CP_Image_Load("./Assets/skunk.png");
	I_Magpie = CP_Image_Load("./Assets/magpie.png");
	I_Hawk = CP_Image_Load("./Assets/hawk.png");
	I_Viper = CP_Image_Load("./Assets/viper.png");
	I_Elephant = CP_Image_Load("./Assets/elephant.png");
	I_SnappingTurtle = CP_Image_Load("./Assets/snappingturtle.png");
	I_Chameleon = CP_Image_Load("./Assets/chameleon.png");
}

void Imagefree()
{
	CP_Image_Free(&I_Spider);
	CP_Image_Free(&I_Hamster);
	CP_Image_Free(&I_Pigeon);
	CP_Image_Free(&I_Sparrow);
	CP_Image_Free(&I_Frog);
	CP_Image_Free(&I_Dog);
	CP_Image_Free(&I_Turtle);
	CP_Image_Free(&I_Chicken);
	CP_Image_Free(&I_Chick);
	CP_Image_Free(&I_Cheerleader);
	CP_Image_Free(&I_PoisonDartFrog);
	CP_Image_Free(&I_Owl);
	CP_Image_Free(&I_Pig);
	CP_Image_Free(&I_Tiger);
	CP_Image_Free(&I_Skunk);
	CP_Image_Free(&I_Magpie);
	CP_Image_Free(&I_Hawk);
	CP_Image_Free(&I_Viper);
	CP_Image_Free(&I_Elephant);
	CP_Image_Free(&I_SnappingTurtle);
	CP_Image_Free(&I_Chameleon);
	CP_Image_Free(&Heart);
	CP_Image_Free(&Sword);
}

void Drawunittext(float posx, float posy, int type)
{
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(50.0f);

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

void Drawunit(struct unit store_unit, float x, float y)
{
	loadimage();
	if (store_unit.type <= 0
		|| store_unit.type > Chameleon)
		return;
	else if (store_unit.type <= Frog)
		CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	else if (store_unit.type <= Cheerleader)
		CP_Settings_Fill(CP_Color_Create(0, 255, 0, 255));
	else if (store_unit.type <= Magpie)
		CP_Settings_Fill(CP_Color_Create(0, 0, 255, 255));
	else if (store_unit.type <= Chameleon)
		CP_Settings_Fill(CP_Color_Create(120, 120, 120, 255));
	CP_Graphics_DrawRect(x, y, 250, 275);

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Graphics_DrawRect(x + 6, y + 6, 238, 238);

	switch (store_unit.type)
	{
	case Spider:
		CP_Image_Draw(I_Spider, x + 125, y + 125, 220, 220, 255);
		break;
	case Hamster:
		CP_Image_Draw(I_Hamster, x + 125, y + 125, 220, 220, 255);
		break;
	case Pigeon:
		CP_Image_Draw(I_Pigeon, x + 125, y + 125, 220, 220, 255);
		break;
	case Sparrow:
		CP_Image_Draw(I_Sparrow, x + 125, y + 125, 220, 220, 255);
		break;
	case Frog:
		CP_Image_Draw(I_Frog, x + 125, y + 125, 220, 220, 255);
		break;
	case Dog:
		CP_Image_Draw(I_Dog, x + 125, y + 125, 220, 220, 255);
		break;
	case Turtle:
		CP_Image_Draw(I_Turtle, x + 125, y + 125, 220, 220, 255);
		break;
	case Chicken:
		CP_Image_Draw(I_Chicken, x + 125, y + 125, 220, 220, 255);
		break;
	case Chick:
		CP_Image_Draw(I_Chick, x + 125, y + 125, 220, 220, 255);
		break;
	case Cheerleader:
		CP_Image_Draw(I_Cheerleader, x + 125, y + 125, 220, 220, 255);
		break;
	case PoisonDartFrog:
		CP_Image_Draw(I_PoisonDartFrog, x + 125, y + 125, 220, 220, 255);
		break;
	case Owl:
		CP_Image_Draw(I_Owl, x + 125, y + 125, 220, 220, 255);
		break;
	case Pig:
		CP_Image_Draw(I_Pig, x + 125, y + 125, 220, 220, 255);
		break;
	case Tiger:
		CP_Image_Draw(I_Tiger, x + 125, y + 125, 220, 220, 255);
		break;
	case Skunk:
		CP_Image_Draw(I_Skunk, x + 125, y + 125, 220, 220, 255);
		break;
	case Magpie:
		CP_Image_Draw(I_Magpie, x + 125, y + 125, 220, 220, 255);
		break;
	case Hawk:
		CP_Image_Draw(I_Hawk, x + 125, y + 125, 220, 220, 255);
		break;
	case Viper:
		CP_Image_Draw(I_Viper, x + 125, y + 125, 220, 220, 255);
		break;
	case Elephant:
		CP_Image_Draw(I_Elephant, x + 125, y + 125, 220, 220, 255);
		break;
	case SnappingTurtle:
		CP_Image_Draw(I_SnappingTurtle, x + 125, y + 125, 220, 220, 255);
		break;
	case Chameleon:
		CP_Image_Draw(I_Chameleon, x + 125, y + 125, 220, 220, 255);
		break;
	}

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 170));
	CP_Graphics_DrawRect(x + 6, y + 190, 238, 50);

	Drawunittext(x + 20, y + 185, store_unit.type);
	//Image att, life
	CP_Image_Draw(Sword, x + 25, y + 250, 50, 50, 255);
	CP_Image_Draw(Heart, x + 225, y + 250, 50, 50, 255);

	drawunitlife(store_unit.life, x, y+45);
	drawunitatt(store_unit.att, x, y+45);
	//DrawATT
}

void drawupgradestore()
{
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(30.0f);

	char buffer[20];
	sprintf_s(buffer, 20, "shop level: %d", shopLevel);
	CP_Font_DrawText(buffer, teamPosX + 40, shopPosY + 20);

	if (shopLevel != MAX_SHOP_LEVEL)
	{
		sprintf_s(buffer, 20, "upgrade cost: %d", costShopUpgrade[shopLevel] + upgradeShopDiscount);
		CP_Font_DrawText(buffer, teamPosX + 40, shopPosY + 20 + 32);
	}
}

//combat
void drawunitlife(int life, float unitx, float unity)
{
	float x = unitx + 240 - 25;
	float y = unity + 180;
	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "%d", life);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(50.0f);
	CP_Font_DrawText(buffer, x, y);
}
void drawunitatt(int att, float unitx, float unity)
{
	float x = unitx + 10;
	float y = unity + 180;
	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "%d", att);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(50.0f);
	CP_Font_DrawText(buffer, x, y);
}

void combat_interface()
{
	CP_Settings_Stroke(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 130));

	float enemyPosX = teamPosX + cardWidth * 3;

	for (int i = 0; i < 4; i++)
	{
		CP_Graphics_DrawRect(teamPosX + cardWidth * i, teamPosY, cardWidth, cardHeight);
		CP_Graphics_DrawRect(enemyPosX + cardWidth * i, shopPosY, cardWidth, cardHeight);
	}
}

void drawfightteam(struct unit* team, float x, float y, int enemyT)
{
	const float amplitude = 75.0;

	for (int i = 1; i < 3; i++)
	{
		float vx = x + cardWidth * i;
		float vy = y;
		Drawunit(team[i], vx, vy);
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
		double ratio = team[0].time / /*abc[0].Maxtime*/1.f;

		float vy = (float)sin( ratio * PI ) * amplitude;

		Drawunit(team[0], x, y - vy);
		Drawunit(team[3], x + 250 * 3, y);
	}
	else //team
	{
		//Do up down
		double ratio = team[3].time / /* abc[3].Maxtime*/ 1.f;

		float vy = (float)sin(ratio * PI) * amplitude;

		Drawunit(team[3], x + 250 * 3, y + vy);
		Drawunit(team[0], x, y);
	}
}

int checksell()
{
	if (releasedrect(lowerBtnPosX, lowerBtnPosY - (btnHeight + 10), btnWidth, btnHeight))
	{
		return 1;
	}
	return 0;
}

void ShowUnitDescription(struct unit* unit)
{
	static char name[20];
	static char description[150];
	if (unit->type != 0)
	{
		strcpy_s(name, 20, unit->name);
		strcpy_s(description, 150, unit->description);
	}

	CP_Settings_NoStroke();
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 180));
	CP_Graphics_DrawRectAdvanced(lowerBtnPosX, teamPosY, (btnWidth + 10) * 3, cardHeight, 0.f, 30.f);

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(30.f);
	CP_Font_DrawTextBox(name, lowerBtnPosX + 20, teamPosY + 10, (btnWidth + 10) * 3 - 40);
	CP_Font_DrawTextBox(description, lowerBtnPosX + 20, teamPosY + 40, (btnWidth + 10) * 3 - 40);
}