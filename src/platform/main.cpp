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

/*#include <iostream>

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
}*/

#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

#include <gameMain.h>


int main(void)
{

    #if PRODUCTION_BUILD == 1
    SetTraceLogLevel(LOG_NONE); // no log output to the console by raylib
    #endif

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "window name");
    SetExitKey(KEY_NULL); // Disable Esc from closing window
    SetTargetFPS(240);

    #pragma region imgui
    rlImGuiSetup(true);


    ImGuiIO &io = ImGui::GetIO(); (void)io;
    ////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    ////io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;       // Enable gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
    io.FontGlobalScale = 2;

    #pragma endregion


    if (!initGame())
    {
        //permaAssert(1 == 2);
        return 0;
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        #pragma region imgui
        rlImGuiBegin();

        //docking stuff
        ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
        ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
        ImGui::DockSpaceOverViewport(
            0,
            ImGui::GetMainViewport()
        );        ImGui::PopStyleColor(2);
        #pragma endregion

        if (!updateGame())
        {
            CloseWindow();
        }

        #pragma region imgui
        rlImGuiEnd();

        #pragma endregion

        EndDrawing();
    }

    CloseWindow();

    closeGame();

    #pragma region imgui
    rlImGuiShutdown();
    #pragma endregion


    return 0;
}

