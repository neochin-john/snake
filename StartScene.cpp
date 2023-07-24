#include "StartScene.h"
#include "Game.h"
#include <raylib.h>

#include <iostream>

void StartScene::Update() {
  if (IsKeyPressed(KEY_ENTER)) {
    Game::Instance()->SwitchScene("main");
    std::cout << "Start Scene Press Enter" << std::endl;
  }
}

void StartScene::Rende() {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  int screenWidth = Game::Instance()->ScreenWidth();
  int screenHeight = Game::Instance()->ScreenHeight();

  DrawText("PRESS [ENTER] TO PLAY",
           screenWidth / 2 - MeasureText("PRESS [ENTER] TO PLAY", 20) / 2,
           screenHeight / 2 - 50, 20, GRAY);
  EndDrawing();
}
