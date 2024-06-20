#include "clickobject.h"
//click == 1, else == 0
int triggeredrect(float posx, float posy, float width, float height) 
{
	float x = CP_Input_GetMouseX();
	float y = CP_Input_GetMouseY();

	if (CP_Input_MouseTriggered(MOUSE_BUTTON_1) && (posx <= x && x <= posx + width) && (posy <= y && y <= posy + height))
	{
		return 1;
	}
	return 0;
}

int clickedrect(float posx, float posy, float width, float height)
{
	float x = CP_Input_GetMouseX();
	float y = CP_Input_GetMouseY();

	if (CP_Input_MouseClicked() && (posx <= x && x <= posx + width) && (posy <= y && y <= posy + height))
	{
		return 1;
	}
	return 0;
}


int clickimage(float posx, float posy, float width, float height)
{
	float x = CP_Input_GetMouseX();
	float y = CP_Input_GetMouseY();
	if (CP_Input_MouseTriggered(MOUSE_BUTTON_1) && ((posx - width / 2)<= x && x <= (posx + width / 2))
		&& ((posy - height / 2) <= y && y <= (posy - height / 2)))
	{
		return 1;
	}
	return 0;
}

int clicktext(float posx, float posy, float wordsize, float wordcount)
{
	float width = (wordsize / 2) * wordcount;
	float height = (wordsize / 2) * 6 / 5;

	float x = CP_Input_GetMouseX();
	float y = CP_Input_GetMouseY();

	if (CP_Input_MouseClicked() && (posx <= x && x <= posx + width) && (posy >= y && y >= posy - height))
	{
		return 1;
	}
	return 0;
}
int releasedrect(float posx, float posy, float width, float height)
{
	float x = CP_Input_GetMouseX();
	float y = CP_Input_GetMouseY();

	if (posx <= x && x <= posx + width && (posy <= y && y <= posy + height))
	{
		return 1;
	}
	return 0;
}
