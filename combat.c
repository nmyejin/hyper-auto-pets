#include "combat.h"

//CP_Image heart = NULL;
//CP_Image att = NULL;

int fightover = 0;
double T = 0;

void combat_init(void)
{
	CP_Settings_TextAlignment(CP_TEXT_ALIGN_H_LEFT, CP_TEXT_ALIGN_V_TOP);
	CP_System_SetWindowSize(2000, 1000);
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	summonenemyteam(stage);
	fillin_team_emptyslot();

	//heart = CP_Image_Load("./Assets/heart.ppm");
	//att = CP_Image_Load("./Assets/att.ppm");
}
void combat_update(void)
{
	if (T >= 2) {
		//Update the teams animals
		team[0].time += CP_System_GetDt();
		enemy[0].time += CP_System_GetDt();


		//Update the timers

		//When the timer = max time, they hit
		if (team->Maxtime <= team->time)
		{
			hit();
			if (checkdead() == 0)
			{
				team[0].type = 0;
				enemy[3].type = 0;
			}
			if (checkdead() == 1)
			{
				enemy[3].type = 0;
			}
			if (checkdead() == 2)
			{
				team[0].type = 0;
			}
			if (team[0].time >= team[0].Maxtime)
				team[0].time = 0;
			if (enemy[0].time >= enemy[0].Maxtime)
				enemy[0].time = 0;
		}
		//Hit
		//Check dead
		//Move team members
		//T = 0;
		//...
	}
	else 
		T += CP_System_GetDt();
	CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));
	combat_interface();
	drawfightteam(team, 125, 100, 0);
	drawfightteam(enemy, 875, 700, 1);
}
void combat_exit(void)
{
	//CP_Image_Free(&heart);
	//CP_Image_Free(&att);
}
