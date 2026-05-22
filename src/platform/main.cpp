/*#include <iostream>

int main(){

    std::cout<<"changing txt, success!\n";
    //git test...

    //raylib test
    std::cout<<"raylib-5.0 linked\n";

}*/

/*#include "raylib.h"

int main(){
    InitWindow(800, 600, "cppGame");

    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //DrawText("Let's go!", 300, 300, 20, BLACK);

        DrawRectangle(75,75,100,100,{0,255,0,255});

        DrawRectangle(50,50,100,100,{255,0,0,255});

        EndDrawing();
    }

    CloseWindow();

    return 0;
}*/

/*#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{
    InitWindow(800,600,"ImGui Test");

    rlImGuiSetup(true);

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        rlImGuiBegin();

        ImGui::ShowDemoWindow();

        rlImGuiEnd();

        EndDrawing();
    }

    rlImGuiShutdown();

    CloseWindow();

    return 0;
}*/

#include <iostream>

#include <raylib.h>

#include <imgui.h>

#include <rlImGui.h>

#include "../gameLayer/gameMain.h"

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(
        800,
        400,
        "window name"
    );

    SetExitKey(KEY_NULL);

    SetTargetFPS(240);

    rlImGuiSetup(true);

    ImGuiIO& io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    io.FontGlobalScale =1;

    if(!initGame())
    {
        return 0;
    }

    while(!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        rlImGuiBegin();

        if(!updateGame())
        {
            CloseWindow();
        }

        rlImGuiEnd();

        EndDrawing();

    }

    CloseWindow();

    closeGame();

    rlImGuiShutdown();

    return 0;
}
