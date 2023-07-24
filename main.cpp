#include <ios>
#include <iostream>
#include <raylib.h>

#include "EndScene.h"
#include "Game.h"
#include "MainScene.h"
#include "StartScene.h"

using namespace std;

int main() {
  const int width = 800, height = 600;
  InitWindow(width, height, "snake");

  // 每10ms一帧
  double fixedFrameTime = 1. / 100;

  Game *game = Game::Instance();
  game->SetFixedFrameTime(fixedFrameTime * 1000);
  game->SetScreenSize(width, height);

  StartScene startScene;
  game->AddScene("start", startScene);
  EndScene endScene;
  game->AddScene("gameover", endScene);
  MainScene mainScene(30, 40);
  game->AddScene("main", mainScene);

  // 用于调试的时间
  double time = GetTime();

  // 上一帧的时间
  double preFrameTime = GetTime();

  // 注释fps控制帧率，我们自己控制帧率
  // SetTargetFPS(100);

  while (!WindowShouldClose()) {
    Game::Instance()->Run();
    // cout << "time: " << (GetTime() - time) << endl;

    // PollInputEvents(); // conflict with EndDrawing()

    double frameRunTime = GetTime() - preFrameTime;
    if (frameRunTime < fixedFrameTime) {
      WaitTime(fixedFrameTime - frameRunTime);
    }

    preFrameTime = GetTime();
  }

  // Close window and OpenGL context
  CloseWindow();
  return 0;
}
