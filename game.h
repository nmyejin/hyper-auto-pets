#pragma once
#include "clickobject.h"
#include "cprocessing.h"
#include "drawunit.h"
#include "shop.h"
#include "unit.h"
#include "stage.h"

void game_init(void);
void game_update(void);
void game_exit(void);


void summonshop();
int checkstorelist(int sl);
void Drawspidertext(float posx, float posy);
void Drawunittext(float posx, float posy, int type);

extern int money;
extern int Playerlife;
extern int stage;
extern int storelevel;
extern int select;

struct unit shop[3];
struct unit team[4];
struct unit enemy[4];