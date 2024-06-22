#pragma once
#include <stdlib.h>
#include <stdio.h>


enum unitlist
{
	//A
	spider = 1,
	hamster = 2,
	pigeon = 3,
	sparrow = 4,
	frog = 5,
	//B
	dog = 6,
	turtle = 7,
	chicken = 8,
	chick = 9,	// Do not appear in the shop
	cheerleader = 10,
	//C
	poisondart_frog = 11,
	owl,
	pig,
	tiger,
	skunk,
	magpie = 16,
	//D
	hawk = 17,
	viper,
	elephant,
	snapping_turtle,
	chameleon = 21
};

struct unit
{
	// bool exist를 추가해서 combat에서 사용하면 따로 fightteam 필요 없음
	double time;
	double Maxtime;
	enum unitlist type;
	int Maxhp, originalatt;
	int att, life;
	//char skill;
};

void LoadUnitFromFile(struct unit* myunit);