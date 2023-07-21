#include "EndScene.h"
#include "Game.h"
#include <raylib.h>

#include <iostream>

void EndScene::Update()
{
    if (IsKeyPressed(KEY_ENTER))
    {
	Game::Instance()->SwitchScene("main");
	std::cout << "End Scene Press Enter" << std::endl;
    }
}

void EndScene::Rende()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);

    int screenWidth = Game::Instance()->ScreenWidth();
    int screenHeight = Game::Instance()->ScreenHeight();
    
    DrawText(
	"GAME OVER\nPRESS [ENTER] TO PLAY AGAIN",
	screenWidth/2 - MeasureText("GAME OVER\nPRESS [ENTER] TO PLAY AGAIN", 20)/2,
	screenHeight/2 - 50,
	20,
	GRAY);
    EndDrawing();
}
