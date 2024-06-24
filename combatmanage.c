#include "combatmanage.h"

int moneyEnemy;

int periodUpgradeShopEnemy = FINAL_STAGE / MAX_SHOP_LEVEL;
int shopLevelEnemy = 0;
int result = 0;

struct unit teamEnemy[TEAM_SIZE];
struct unit shopEnemy[SHOP_SIZE];

void SummonTeamEnemy()
{
	static int stageBefore = 0;

	if (stageBefore != stage && stage % periodUpgradeShopEnemy == 1)
		shopLevelEnemy++;
	SummonShop(shopEnemy, shopLevelEnemy);

	while (moneyEnemy > 0)
	{
		CP_Vector shopEnemyInfo = IdxMaxPower(shopEnemy, SHOP_SIZE);	// pair(idx, value)
		CP_Vector enemyInfo = IdxMinPower(teamEnemy, TEAM_SIZE);

		if (shopEnemyInfo.y >= enemyInfo.y)
		{
			if (teamEnemy[(int)enemyInfo.x].type != 0)
				SellUnit(teamEnemy, (int)enemyInfo.x, &moneyEnemy);
			BuyUnit(shopEnemy, teamEnemy, (int)shopEnemyInfo.x, (int)enemyInfo.x, &moneyEnemy);
		}
		else if (moneyEnemy >= 4)
		{
			moneyEnemy--;
			SummonShop(shopEnemy, shopLevelEnemy);
		}
		
		if (moneyEnemy < 4)
			break;
	}

	stageBefore = stage;
}

void hit()
{	
	snasnapping_turtleskill();

	fightPlayer[3].life -= fightEnemy[0].att;
	fightEnemy[0].life -= fightPlayer[3].att;
}

void checkdead()
{
	for (int i = 0; i < 4; i++) {
		if (fightPlayer[i].life <= 0)
		{
			fightPlayer[i].type = 0;
		}
		if (fightEnemy[i].life <= 0)
		{
			fightEnemy[i].type = 0;
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
	if (1 <= fightPlayer[3].time)
	{
		hit();
		switch (fightPlayer[3].type)
		{
		case Turtle:
			turtleskill(&fightPlayer[3], &fightEnemy[0]);
			break;
		case Skunk:
			skunkskill(&fightteam[3], &fightEnemy[0], 1);
			break;
		case Owl:
			owlskill();
			break;
		case PoisonDartFrog:
			poisondartfrogskill(&fightEnemy[0]);
			break;
		case Hawk:
			hawkskill();
			break;
		case Elephant:
			elephantskill();
			break;
		case Viper:
			viperskill();
		}

		switch (fightEnemy[0].type)
		{
		case Turtle:
			turtleskill(&fightEnemy[0], &fightPlayer[3]);
			break;
		case Skunk:
			skunkskill(&fightEnemy[0], &fightPlayer[3], 0);
			break;
		case Owl:
			owlskill();
			break;
		case PoisonDartFrog:
			poisondartfrogskill(&fightPlayer[3]);
			break;
		case Hawk:
			hawkskill();
			break;
		case Elephant:
			elephantskill();
			break;
		case Viper:
			viperskill();
		}

		checkdead();

		fightPlayer[3].time = 0;
		fightEnemy[0].time = 0;
	}
}

void timer()
{
	for (int i = 0; i < 4; i++)
	{
		fightPlayer[i].time += CP_System_GetDt();
		fightEnemy[i].time += CP_System_GetDt();
	}
}

int checkcombatover()
{
	int t = 0;
	for (int i = 0; i < 4; i++) {
		if (fightPlayer[i].type == 0)
			t++;
	}
	int e = 0;
	for (int i = 0; i < 4; i++) {
		if (fightEnemy[i].type == 0)
			e++;
	}

	defeatLastCombat = 0;
	if (e == 4 && t == 4)//draw
	{
		givemoneystage();
		CP_Engine_SetNextGameState(GameInit, GameUpdate, GameExit);
		return 2;
	}
	if (t == 4)//lose
	{
		defeatLastCombat = 1;
		givemoneystage();
		playerLife -= 1;
		if (checkgameover())
			return 0;
		CP_Engine_SetNextGameState(GameInit, GameUpdate, GameExit);
		return 0;
	}
	if (e == 4)//win
	{	
		stage++;
		checkgameover();
		if (checkgameover())
			return 0;
		CP_Engine_SetNextGameState(GameInit, GameUpdate, GameExit);

		return 1;
	}
	return -1;
}

void InitializeTeam()
{
	for (int i = 0; i < 4; i++)
	{
		fightPlayer[i] = teamPlayer[i];
		fightEnemy[i] = teamEnemy[i];
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
	case FINAL_STAGE:
		money += 20;
	}

}

void turtleskill(struct unit* turtle, struct unit* object)
{
	turtle->life += object->att / 2;
}

void skunkskill(struct unit* skunk, struct unit* object, int tore)//1= skunk is team
{
	if (skunk->life <= 0) {
		if (tore == 1) {
			for (int i = 1; i < 4; i++)
			{
				object[i].life -= 3;
			}
		}
		if (tore == 0) {
			for (int i = 0; i < 3; i++)
			{
				object[i].life -= 3;
			}
		}
	}
}

void owlskill()
{
	int last;
	if (fightPlayer[3].type == Owl)
	{
		last = 3;
		while (fightEnemy[last].type == 0) {
			last--;
		}
		if (last == 0)
		{
			return;
		}
		else {
			fightEnemy[last].life -= fightPlayer[3].att;
			fightEnemy[0].life += fightPlayer[3].att;
		}
	}
	if (fightEnemy[0].type == Owl)
	{
		last = 0;
		while (fightEnemy[last].type == 0) {
			last++;
		}
		if (last == 3)
		{
			return;
		}
		fightPlayer[last].life -= fightEnemy[0].att;
		fightPlayer[3].life += fightEnemy[0].att;
	}
}

void poisondartfrogskill(struct unit* object)
{
	object->life = -99;
}

void hawkskill()
{
	if (fightPlayer[3].type == Hawk)
	{
		fightEnemy[1].life -= fightPlayer[3].att;
	}
	if (fightEnemy[0].type == Hawk)
	{
    fightteam[2].life -= teamEnemy[0].att;
	}
}

void elephantskill()
{
	if (fightPlayer[3].type == Elephant)
	{
		for (int i = 1; i < 4; i++)
		{
			fightEnemy[i].life -= 2;
		}
	}
	if (fightEnemy[0].type == Elephant)
	{
		for (int i = 0; i < 3; i++)
		{
			fightteam[i].life -= 2;
		}
	}
}

void viperskill()
{
	int talone = 0;
	int ealone = 0;
	for (int i = 0; i < 4; i++)
	{
		if (fightPlayer[i].type != 0)
			talone++;
		if (fightEnemy[i].type != 0)
			ealone++;
	}
	if (talone == 1) {
		fightPlayer[3].att = 100;
		return;
	}
	if (ealone == 1) {
		fightEnemy[0].att = 100;
		return;
	}

	if (fightPlayer[3].type == Viper)
	{
		int r = CP_Random_RangeInt(0, 2);
		while (fightPlayer[r].type == 0)
		{
			r = CP_Random_RangeInt(0, 2);
		}
		fightPlayer[r].att += fightEnemy[0].att;
		fightPlayer[r].life += fightEnemy[0].life;
		fightEnemy[0].life = -99;
	}
	if (fightEnemy[0].type == Viper)
	{
		int r = CP_Random_RangeInt(1, 3);
		while (fightPlayer[r].type == 0)
		{
			r = CP_Random_RangeInt(1, 3);
		}
		fightEnemy[r].att += fightPlayer[3].att;
		fightEnemy[r].life += fightPlayer[3].life;
		fightPlayer[3].life = -99;
	}
}

void snasnapping_turtleskill()
{
	if (fightPlayer[3].type == SnappingTurtle)
	{
		fightEnemy[0].att = 3;
	}
	if (fightEnemy[0].type == SnappingTurtle)
	{
		fightPlayer[3].att = 3;
	}
} 

int checkgameover()
{
	if (playerLife <= 0 || stage > FINAL_STAGE)
	{
		CP_Engine_SetNextGameState(gameover_init, gameover_update, gameover_exit);
		return 1;
	}
	return 0;
}

CP_Vector IdxMaxPower(struct unit* arr, int size)
{
	int idx = 0, value = -1;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].type == 0)
			continue;

		int v = arr[i].att + arr[i].life;
		if (value < v)
		{
			idx = i;
			value = v;
		}
	}

	return CP_Vector_Set((float)idx, (float)value);
}

CP_Vector IdxMinPower(struct unit* arr, int size)
{
	int idx = 0, value = 100000;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].type == 0)
			return CP_Vector_Set((float)i, 0.f);

		int v = arr[i].att + arr[i].life;
		if (value > v)
		{
			idx = i;
			value = v;
		}
	}

	return CP_Vector_Set((float)idx, (float)value);
}

void ShowResult(int r)
{
	CP_Settings_Fill(CP_Color_Create(255, 255, 255, 255));
	CP_Graphics_DrawRect(30, 30, 1970, 970);
	CP_Settings_TextSize(30.0f);

	switch (r)
	{
	case 0:
		CP_Font_DrawText("DRAW", 800, 480);
		break;
	case 1:
		CP_Font_DrawText("WIN", 800, 480);
		break;
	case 2:
		CP_Font_DrawText("LOSE", 800, 480);
		break;
	}
}