#include "gameover.h"

int result;

void gameover_init(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	if (stage == 10)
		result = 2;
	else if (Playerlife <= 0)
		result = 1;
}
void gameover_update(void)
{
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Settings_TextSize(500.0f);
	if (result == 2)
	{
		CP_Font_DrawText("YOU WIN!", 0, 500);
	}
	if (result == 1)
	{
		CP_Font_DrawText("YOU LOSE!", 0, 500);
	}
}
void gameover_exit(void)
{

}