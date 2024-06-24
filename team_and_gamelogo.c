#include "team_and_gamelogo.h"
CP_Image teamlogo = NULL;
CP_Image gamelogo = NULL;
CP_Image madeby = NULL;
double ggTime, gggTime;
double a;
double b;

void logo_init()
{
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	teamlogo = CP_Image_Load("./Assets/hungry.png");
	gamelogo = CP_Image_Load("./Assets/gamelogo.jpg");
	madeby = CP_Image_Load("./Assets/madeby1234.png");
	ggTime = 0;
	gggTime = 0;
	a = 0;
	b = 0;
}
void logo_update()
{
	CP_Graphics_ClearBackground(CP_Color_Create(50, 50, 50, 255));
	if (ggTime < 2)
	{
		a = ggTime * 100;
		CP_Image_Draw(gamelogo, 1000, 400, 600, 600, (int)a);
		ggTime += CP_System_GetDt();
	}
	if (ggTime >= 2)
	{
		b = gggTime * 100;
		CP_Image_Draw(gamelogo, 1000, 400, 600, 600, (int)a);
		CP_Image_Draw(teamlogo, 1300, 900, 141, 141, (int)b);
		CP_Image_Draw(madeby, 900, 900, 647, 141, (int)b);
		gggTime += CP_System_GetDt();
	}
	if (gggTime >= 3)
	{
		CP_Engine_SetNextGameState(startscreen_init, startscreen_update, startscreen_exit);
	}

}
void logo_exit()
{
	CP_Image_Free(&teamlogo);
	CP_Image_Free(&gamelogo);
	CP_Image_Free(&madeby);
}
