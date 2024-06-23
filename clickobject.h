#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "cprocessing.h"

int triggeredrect(float posx, float posy, float width, float height);
int clickimage(float posx, float posy, float width, float height);
int clicktext(float posx, float posy, float wordsize, float wordcount);
int releasedrect(float posx, float posy, float width, float height);
int clickedrect(float posx, float posy, float width, float height);
bool MouseHoverRect(float posx, float posy, float width, float height);