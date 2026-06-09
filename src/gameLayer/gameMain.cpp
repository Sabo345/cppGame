/*#include <raylib.h>

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

}*/

/*#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>

struct GameData
{

    float positionX = 100;
    float positionY = 100;

}gameData;


bool initGame()
{

    return true;
}

bool updateGame()
{
    float deltaTime = GetFrameTime();
    if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

    Color c;
    c.r = 255;
    c.g = 0;
    c.b = 200;
    c.a = 255;


    if (IsKeyDown(KEY_A)) { gameData.positionX -= 200 * deltaTime; }
    if (IsKeyDown(KEY_D)) { gameData.positionX += 200 * deltaTime; }
    if (IsKeyDown(KEY_W)) { gameData.positionY -= 200 * deltaTime; }
    if (IsKeyDown(KEY_S)) { gameData.positionY += 200 * deltaTime; }


    DrawRectangle(gameData.positionX, gameData.positionY, 50, 50, c);

    return true;
}

void closeGame()
{
}*/

/*#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>
#include <assetManager.h>

struct GameData
{
}gameData;

AssetManager assetManager;

bool initGame()
{

    assetManager.loadAll();

    return true;
}

bool updateGame()
{
    float deltaTime = GetFrameTime();
    if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }



    DrawTexturePro(assetManager.dirt, {0,0,(float)assetManager.dirt.width, (float)assetManager.dirt.height},
                   {50, 50, 100, 100}, {}, 0, WHITE);




    return true;
}

void closeGame()
{
}*/

/*#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>
#include <assetManager.h>
#include <gameMap.h>

struct GameData
{
    GameMap gameMap;
    Camera2D camera;

}gameData;

AssetManager assetManager;

bool initGame()
{

    assetManager.loadAll();


    gameData.gameMap.create(30, 10);

    gameData.gameMap.getBlocUnsafe(0, 0).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(1, 1).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(2, 2).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(3, 3).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(4, 4).type = Block::dirt;

    gameData.camera.target = {0, 0};  // world-space center of view, we will use this as the camera position
    gameData.camera.rotation = 0.0f;
    gameData.camera.zoom = 50.0f;

    return true;
}

bool updateGame()
{
    float deltaTime = GetFrameTime();
    if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

    gameData.camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    ClearBackground({75, 75, 150, 255});


    #pragma region camera movement

    if (IsKeyDown(KEY_LEFT)) gameData.camera.target.x -= 7.f * deltaTime;
    if (IsKeyDown(KEY_RIGHT)) gameData.camera.target.x += 7.f * deltaTime;
    if (IsKeyDown(KEY_UP)) gameData.camera.target.y -= 7.f * deltaTime;
    if (IsKeyDown(KEY_DOWN)) gameData.camera.target.y += 7.f * deltaTime;

    #pragma endregion

    #pragma region draw world

    BeginMode2D(gameData.camera);

    for (int y = 0; y < gameData.gameMap.h; y++)
        for (int x = 0; x < gameData.gameMap.w; x++)
        {

            auto &b = gameData.gameMap.getBlocUnsafe(x, y);

            if (b.type != Block::air)
            {
                //todo remove this useless size here
                float size = 1;
                float posX = x * size;
                float posY = y * size;

                DrawTexturePro(
                    assetManager.dirt,
                    Rectangle{0.f, 0.f, (float)assetManager.dirt.width, (float)assetManager.dirt.height}, //source
                               {posX, posY, size, size}, //dest
                               {0, 0},// origin (top-left corner)
                0.0f, // rotation
                WHITE // tint
                );

            }


        }

        EndMode2D();


        #pragma endregion


        return true;
}

void closeGame()
{
}*/

#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>
#include <assetManager.h>
#include <gameMap.h>
#include <helpers.h>

struct GameData
{
    GameMap gameMap;
    Camera2D camera;

}gameData;

AssetManager assetManager;

bool initGame()
{

    assetManager.loadAll();


    gameData.gameMap.create(30, 10);

    gameData.gameMap.getBlocUnsafe(0, 0).type = Block::dirt;
    gameData.gameMap.getBlocUnsafe(1, 1).type = Block::grassBlock;
    gameData.gameMap.getBlocUnsafe(2, 2).type = Block::goldBlock;
    gameData.gameMap.getBlocUnsafe(3, 3).type = Block::glass;
    gameData.gameMap.getBlocUnsafe(4, 4).type = Block::platform;

    gameData.camera.target = {0, 0};  // world-space center of view
    gameData.camera.rotation = 0.0f;
    gameData.camera.zoom = 50.0f;

    return true;
}

bool updateGame()
{
    float deltaTime = GetFrameTime();
    if (deltaTime > 1.f / 5) { deltaTime = 1 / 5.f; }

    gameData.camera.offset = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};

    ClearBackground({75, 75, 150, 255});


    #pragma region camera movement

    if (IsKeyDown(KEY_LEFT)) gameData.camera.target.x -= 7.f * GetFrameTime();
    if (IsKeyDown(KEY_RIGHT)) gameData.camera.target.x += 7.f * GetFrameTime();
    if (IsKeyDown(KEY_UP)) gameData.camera.target.y -= 7.f * GetFrameTime();
    if (IsKeyDown(KEY_DOWN)) gameData.camera.target.y += 7.f * GetFrameTime();

    #pragma endregion

    #pragma region draw world

    BeginMode2D(gameData.camera);

    for (int y = 0; y < gameData.gameMap.h; y++)
        for (int x = 0; x < gameData.gameMap.w; x++)
        {

            auto &b = gameData.gameMap.getBlocUnsafe(x, y);

            if (b.type != Block::air)
            {

                Rectangle textureUV;
                textureUV.width = 32;
                textureUV.height = 32;
                textureUV.x = b.type * 32;
                textureUV.y = 0;

                DrawTexturePro(
                    assetManager.textures,
                    getTextureAtlas(b.type, 0, 32, 32), //source
                               {(float)x, (float)y, 1, 1}, //dest
                               {0, 0},// origin (top-left corner)
                0.0f, // rotation
                WHITE // tint
                );

            }


        }

        EndMode2D();


        #pragma endregion


        return true;
}

void closeGame()
{
}


