#include "stage.h"

void stage_init(void)
{
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(0, 0, 0, 255));
}
void stage_update(void)
{
	char stagebuffer[50] = { 0 };
	sprintf_s(stagebuffer, 50, "STAGE  %d", stage);
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Settings_TextSize(200.0f);
	CP_Font_DrawText(stagebuffer, 0, 250);

	if(CP_Input_MouseClicked())
		CP_Engine_SetNextGameState(combat_init, combat_update, combat_exit);
}
void stage_exit(void)
{

}