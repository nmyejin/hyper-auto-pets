#include "howto.h"

CP_Image g_howtoimage = NULL;
CP_Image g_exit = NULL;

void howto_init()
{
    CP_System_SetWindowSize(1200, 800);
    g_howtoimage = CP_Image_Load("./Assets/howto.png");
    g_exit = CP_Image_Load("./Assets/exit.png");
}
void howto_update()
{
    CP_Graphics_ClearBackground(CP_Color_Create(255, 255, 255, 255));

    float x = CP_Input_GetMouseX();
    float y = CP_Input_GetMouseY();

    CP_Image_Draw(g_howtoimage, 600, 400, 1200, 800, 255);
    CP_Image_Draw(g_exit, 1100, 750, 200, 100, 255);
    if ((900 <= x && x <= 1200) && (y <= 800 && 700 <= y) && CP_Input_MouseClicked())
    {
        CP_Engine_SetNextGameState(startscreen_init, startscreen_update, startscreen_exit);
    }
    //
    CP_Settings_TextSize(20.0f);
    char buffer[50] = { 0 };
    sprintf_s(buffer, 50, "Mousepointpos: %f, %f", CP_Input_GetMouseX(), CP_Input_GetMouseY());
    CP_Font_DrawText(buffer, 30, 30);
    //
}
void howto_exit()
{
    CP_Image_Free(&g_howtoimage);
}