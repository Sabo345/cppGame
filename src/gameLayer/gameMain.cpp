#include <raylib.h>

#include <imgui.h>

#include "gameMain.h"

bool initGame()
{
    return true;
}

bool updateGame()
{
    Color c;

    c.r = 255;
    c.g = 0;
    c.b = 200;
    c.a = 255;

    DrawText(
        "Congrats! u created ur 1st window!",
        100,
        200,
        20,
        c
    );

    ImGui::ShowDemoWindow();

    return true;
}

void closeGame()
{

}
