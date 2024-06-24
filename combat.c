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

	SummonTeamEnemy();
	InitializeTeam();

	fillin_emptyslot(fightPlayer, 0);
	T = 0;

}
void combat_update(void)
{
	if (T >= 1) {
		fillin_emptyslot(fightPlayer, 0);
		fillin_emptyslot(fightEnemy, 1);
		timer();
		CheckHit();
	}
	else 
		T += CP_System_GetDt();
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	combat_interface();
	drawfightteam(fightPlayer, teamPosX, teamPosY, 0);
	drawfightteam(fightEnemy, teamPosX + cardWidth * 3, shopPosY, 1);
	checkcombatover();
}
void combat_exit(void)
{
	ShowResult(result);
}
