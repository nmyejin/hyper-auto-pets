#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

enum unitlist
{
	//A
	Spider = 1,
	Hamster,
	Pigeon,
	Sparrow,
	Frog = 5,

	//B
	Dog = 6,
	Turtle,
	Chicken,
	Chick = 9,	// Do not appear in the shop
	Cheerleader = 10,

	//C
	PoisonDartFrog = 11,
	Owl,
	Pig,
	Tiger,
	Skunk,
	Magpie = 16,

	//D
	Hawk = 17,
	Viper,
	Elephant,
	SnappingTurtle,
	Chameleon = 21
};

struct unit
{
	//bool visible;
	double time;
	double Maxtime;
	enum unitlist type;
	int Maxhp, originalatt;
	int att, life;
	//char skill;
	char description[150];
	char name[20];
};

void InitializeUnit(struct unit* unit, enum unitlist ul);
void LoadUnitFromFile(struct unit* myunit);