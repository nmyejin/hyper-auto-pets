#include "cprocessing.h"
#include "digipen.h"

CP_Image digipenlogo = NULL;
double gTime;

void digipen_init()
{
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
	digipenlogo = CP_Image_Load("./Assets/DigiPen_WHITE.png");
	gTime = 0;
}
void digipen_update()
{
	double a = gTime * 100;
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, (int)a));
	if (gTime > 3)
	{
		CP_Engine_SetNextGameState(logo_init, logo_update, logo_exit);
	}
	else
	{
		CP_Image_Draw(digipenlogo, 1000, 500, 1026, 249, (int)a);
		gTime += CP_System_GetDt();
	}
}
void digipen_exit()
{
	CP_Image_Free(&digipenlogo);
}
