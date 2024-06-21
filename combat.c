#include "combat.h"

//CP_Image heart = NULL;
//CP_Image att = NULL;

int fightover = 0;
double T;

void combat_init(void)
{
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_TOP);
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	teamintofightteam();
	summonenemyteam(stage);
	fillin_emptyslot(fightteam, 0);
	T = 0;
	howmanyturtle();
	//heart = CP_Image_Load("./Assets/heart.ppm");
	//att = CP_Image_Load("./Assets/att.ppm");
}
void combat_update(void)
{
	if (T >= 1) {
		
		fillin_emptyslot(fightteam, 0);
		fillin_emptyslot(enemy, 1);
		timer();
		CheckHit();
	}
	else 
		T += CP_System_GetDt();
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	combat_interface();
	drawfightteam(fightteam, 125, 100, 0);
	drawfightteam(enemy, 875, 700, 1);
	checkcombatover();
}
void combat_exit(void)
{
	//CP_Image_Free(&heart);
	//CP_Image_Free(&att);
}
