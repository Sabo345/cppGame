/*#include <iostream>

int main(){

    std::cout<<"changing txt, success!\n";
    //git test...

    //raylib test
    std::cout<<"raylib-5.0 linked\n";

}*/

#include "raylib.h"

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
}
