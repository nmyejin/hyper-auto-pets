#include "howto.h"

CP_Image g_howtoimage = NULL;
CP_Image g_exit = NULL;

void howto_init()
{
    CP_System_SetWindowSize(2000, 1000);
    g_howtoimage = CP_Image_Load("./Assets/howto.png");
    g_exit = CP_Image_Load("./Assets/exit.png");
}
void howto_update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(3, 29, 56, 255));

    float x = CP_Input_GetMouseX();
    float y = CP_Input_GetMouseY();

    CP_Image_Draw(g_howtoimage, 1000, 500, 2000, 1000, 255);
    CP_Image_Draw(g_exit, 1900, 950, 200, 100, 255);
    if ((1800 <= x && x <= 2000) && (y <= 1000 && 800 <= y) && CP_Input_MouseClicked())
    {
        CP_Engine_SetNextGameState(startscreen_init, startscreen_update, startscreen_exit);
    }
}
void howto_exit()
{
    CP_Image_Free(&g_howtoimage);
}