#include "combatmanage.h"

void summonenemyteam(int whichstage)
{
	for (int i = 0; i < 4; i++)
	{
		enemy[i].type = 0;
		LoadUnitFromFile(&enemy[i]);
	}
	int buffer[4] = { 0 };
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (whichstage == j+1)
			{
				buffer[i] = CP_Random_RangeInt(j*2, (j * 2)+2);
				--buffer[i];
			}
		}
	}
	if (buffer[0] <= 0 && buffer[1] <= 0 && buffer[2] <= 0 && buffer[3] <= 0)
	{
		buffer[0] = 1;
	}
	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (buffer[i] > 0) 
		{
			enemy[j].type = buffer[i];
			LoadUnitFromFile(&enemy[j]);
			j++;
		}
	}
}
void hit()
{	
	snasnapping_turtleskill();
	if (turtleskillused != 0) {
		turtleskill();
		turtleskillused--;
	}
	fightteam[3].life -= enemy[0].att;
	enemy[0].life -= fightteam[3].att;
}
void checkdead()
{
	for (int i = 0; i < 4; i++) {
		if (fightteam[i].life <= 0)
		{
			fightteam[i].type = 0;
		}
		if (enemy[i].life <= 0)
		{
			enemy[i].type = 0;
		}
	}
}


// Todo team type [1, 0, 0, 1] => [0, 0, 1, 1] 
void fillin_emptyslot(struct unit* abc, int enemyT)// enemy 1 team 0
{
	if (abc[1].type == 0 && abc[2].type == 0)
	{
		if (enemyT == 0) // team
		{
			abc[2] = abc[0];
			abc[0].type = 0;
		}
		else if (enemyT == 1) // enemy
		{
			abc[1] = abc[3];
			abc[3].type = 0;
		}
	}

	if (enemyT == 0) // team
	{
		for (int i = 3; i > 0; i--)
		{
			if (abc[i].type == 0)
			{
				abc[i] = abc[i - 1];
				abc[i].time = 0;
				abc[i - 1].type = 0;

			}
		}
	}
	else if (enemyT == 1) // enemy
	{
		for (int i = 0; i < 3; i++)
		{
			if (abc[i].type == 0)
			{
				abc[i] = abc[i + 1];
				abc[i].time = 0;
				abc[i + 1].type = 0;
			}
		}
	}
}

void CheckHit()
{
	if (1 <= fightteam[3].time)
	{
		hit();
		skunkskill();
		owlskill();
		poisondartfrogskill();
		hawkskill();
		elephantskill();
		viperskill();
		checkdead();

		fightteam[3].time = 0;
		enemy[0].time = 0;
	}
}

void timer()
{
	for (int i = 0; i < 4; i++)
	{
		fightteam[i].time += CP_System_GetDt();
		enemy[i].time += CP_System_GetDt();
	}
}

int checkcombatover()
{
	int t = 0;
	for (int i = 0; i < 4; i++) {
		if (fightteam[i].type == 0)
			t++;
	}
	int e = 0;
	for (int i = 0; i < 4; i++) {
		if (enemy[i].type == 0)
			e++;
	}

	if (e == 4 && t == 4)//draw
	{
		givemoneystage();
		CP_Engine_SetNextGameState(game_init, game_update, game_exit);
		return 2;
	}
	if (t == 4)//lose
	{
		givemoneystage();
		Playerlife -= 1;
		CP_Engine_SetNextGameState(game_init, game_update, game_exit);
		return 0;
	}
	if (e == 4)//win
	{	
		stage++;
		givemoneystage();
		CP_Engine_SetNextGameState(game_init, game_update, game_exit);
		return 1;
	}
	return -1;
}
void teamintofightteam()
{
	for (int i = 0; i < 4; i++)
	{
		fightteam[i] = team[i];
	}
}
void givemoneystage()
{

	switch (stage)
	{
	case 1:
		money = money;
		break;
	case 2:
		money += 2;
		break;
	case 3:
		money += 4;
		break;
	case 4:
		money += 8;
		break;
	case 5:
		money += 10;
		break;
	case 6:
		money += 12;
		break;
	case 7:
		money += 14;
		break;
	case 8:
		money += 16;
		break;
	case 9:
		money += 18;
		break;
	case 10:
		money += 20;
		break;
	}

}

void howmanyturtle()
{
	turtleskillused = 0;
	for (int i = 0; i < 4; i++)
	{
		if (fightteam[i].type == 7 || enemy[i].type == 7)
			turtleskillused++;
	}
}

void turtleskill()
{
	for (int i = 0; i < 4; i++)
	{
		if (fightteam[3].type == turtle)
		{
			fightteam[3].life += enemy[0].att;
			if (enemy[0].type == turtle)
			{
				enemy[0].life += fightteam[3].att;
				return;
			}
			return;
		}

	}
}

void skunkskill()
{
	if (fightteam[3].type == skunk && fightteam[3].life <= 0)
	{
		for (int i = 0; i < 4; i++)
		{
			enemy[i].life -= 3;
		}
	}
}

void owlskill()
{
	if (fightteam[3].type == owl)
	{
		enemy[3].life -= fightteam[3].att;
		enemy[0].life += fightteam[3].att;
	}
}

void poisondartfrogskill()
{
	if (fightteam[3].type == poisondart_frog && fightteam[3].life <= 0)
	{
		enemy[0].life = -99;
	}
}

void hawkskill()
{
	if (fightteam[3].type == hawk)
	{
		enemy[1].life -= fightteam[3].att;
	}
}

void elephantskill()
{
	if (fightteam[3].type == elephant)
	{
		for (int i = 1; i < 4; i++)
		{
			enemy[i].life -= 2;
		}
	}
}

void viperskill()
{
	if (fightteam[3].type == viper)
	{
		int r = CP_Random_RangeInt(0, 2);
		while (fightteam[r].type != 0) 
		{
			r = CP_Random_RangeInt(0, 2);
		}
		fightteam[r].att += enemy[0].att;
		fightteam[r].life += enemy[0].life;
		enemy[0].life = -99;
	}
}

void snasnapping_turtleskill()
{
	if (fightteam[3].type == snapping_turtle)
	{
		enemy[0].life = 1;
	}
} 

void checkgameover()
{
	if (Playerlife <= 0)
	{
		CP_Engine_SetNextGameState(game_init, game_update, game_exit);
	}
}