#include "gameover.h"

CP_Image win = NULL;
CP_Image lose = NULL;

int result;

void gameover_init(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	if (stage == 10)
		result = 2;
	else if (playerLife <= 0)
		result = 1;
	win = CP_Image_Load("./Assets/youlose.png");
	lose = CP_Image_Load("./Assets/youwin.png");
}
void gameover_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	if (result == 2)
	{
		CP_Image_Draw(win, 1000, 500, 2000, 1000, 255);
	}
	if (result == 1)
	{
		CP_Image_Draw(lose, 1000, 500, 2000, 1000, 255);
	}
}
void gameover_exit(void)
{
	CP_Image_Free(&win);
	CP_Image_Free(&lose);
}

//test