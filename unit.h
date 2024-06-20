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
	cheerleader = 9,
	//C
	poisondart_frog = 10,
	owl = 11,
	pig = 12,
	tiger = 13,
	skunk = 14,
	magpie = 15,
	//D
	hawk = 16,
	viper = 17,
	elephant = 18,
	snapping_turtle = 19,
	chameleon = 20
};

struct unit
{
	double time;
	double Maxtime;
	enum unitlist type;
	int Maxhp, originalatt;
	int att, life;
	//char skill;
};

void LoadUnitFromFile(struct unit* myunit);