#include "start_screen.h"
CP_Image backgroundimage = NULL;

void startscreen_init(void)
{
	CP_System_SetWindowSize(2000, 1000);
	backgroundimage = CP_Image_Load("./Assets/titleimage.jpg");
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_BOTTOM);
}


int ishowtoclicked()
{
	if (clicktext(130, 850, 170, 6) == 1)
	{
		return 1;
	}
	return 0;
}

int isstartclicked()
{
	if (clicktext(970, 850, 170, 5) == 1)
	{
		return 1;
	}
	return 0;
}

void startscreen_update(void)
{
	if (startscreen() == 1)//howto
	{
		CP_Engine_SetNextGameState(howto_init, howto_update, howto_exit);
		CP_Engine_Run();
	}
	else if (startscreen() == 2)//start
	{
		CP_Engine_SetNextGameState(GameInit, GameUpdate, GameExit);
		CP_Engine_Run();
	}
	CP_Settings_TextSize(20.0f);
	char buffer[50] = { 0 };
	sprintf_s(buffer, 50, "Mousepointpos: %f, %f", CP_Input_GetMouseX(), CP_Input_GetMouseY());
	CP_Font_DrawText(buffer, 30, 30);
}


void startscreen_exit(void)
{
	CP_Image_Free(&backgroundimage);
}

int startscreen() //return 1 => start the game
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	CP_Image_Draw(backgroundimage, 1000, 500, 2000, 1000, 255);

	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 150));
	CP_Graphics_DrawRect(110, 240, 1320, 170);
	CP_Graphics_DrawRect(135, 715, 525, 115);
	CP_Graphics_DrawRect(970, 715, 425, 115);

	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(200.0f);
	CP_Font_DrawText("   Hypher Auto Pets", 0, 400);
	CP_Settings_TextSize(170.0f);
	CP_Font_DrawText("HOW TO", 130, 850);
	CP_Font_DrawText("START", 970, 850);

	if (ishowtoclicked() == 1)
	{
		return 1;
	}
	if (isstartclicked() == 1)
	{
		return 2;
	}
	return 0;
}


