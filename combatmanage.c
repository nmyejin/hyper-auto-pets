#include "combatmanage.h"

void summonenemyteam(int whichstage)
{
	for (int i = 0; i < 4; i++)
	{
		enemy[i].type = 0;
		LoadUnitFromFile(&enemy[i]);
	}
	int buffer[4] = { 0 };
	for (int j = 1; j < 11; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			if (whichstage == j)
			{
				buffer[i] = CP_Random_RangeInt(j * 2 - 3 + 1, j * 2 + 1);
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
	team->life -= enemy->att;
	enemy->life -= team->att;
}
int checkdead()
{
	if (team->life <= 0 && enemy->life <= 0) // both dead
		return 0;
	if (team->life > 0 && enemy->life <= 0) // enemy dead, team alive
		return 1;
	if (team->life <= 0 && enemy->life > 0) // enemy alive, team dead
		return 2;
	if (team->life > 0 && enemy->life > 0) // both alive
		return 3;
	return -1;
}

void fillin_team_emptyslot()
{
	for (int i = 1; i < 4; i++)
	{
		if (team[i].type == 0)
		{
			team[i].type = team[i - 1].type;
			team[i - 1].type = 0;
		}
	}
}