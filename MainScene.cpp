#include "MainScene.h"
#include "Game.h"
#include <iostream>
#include <raylib.h>

MainScene::MainScene(int mapRows, int mapCols)
    : map(mapRows, mapCols), snake({.0f, .0f}) {
  int rSize = Game::Instance()->ScreenWidth() / map.Cols();
  int cSize = Game::Instance()->ScreenHeight() / map.Rows();
  blockSize = std::min(rSize, cSize);
  Init();
}

void MainScene::Init() {
  this->lastSnakeMoveFrame = 0;
  GenFood();
  snake.ReInit({map.Cols() / 2.f, map.Rows() / 2.f});
}

void MainScene::Update() {
  frame++;
  int moveStep = 0;

  Snake::Direction keyDirection = Snake::UNKNOWN;
  if (IsKeyPressed(KEY_UP)) {
    keyDirection = Snake::UP;
  } else if (IsKeyPressed(KEY_RIGHT)) {
    keyDirection = Snake::RIGHT;
  } else if (IsKeyPressed(KEY_DOWN)) {
    keyDirection = Snake::DOWN;
  } else if (IsKeyPressed(KEY_LEFT)) {
    keyDirection = Snake::LEFT;
  }

  if (keyDirection != Snake::UNKNOWN && snake.SetDirection(keyDirection)) {
    moveStep = 1;
  }

  double fixedFrameTime = Game::Instance()->FixedFrameTime();
  int deltaFrame = frame - lastSnakeMoveFrame;
  std::cout << "preMoveStep: " << snake.Speed() * deltaFrame * fixedFrameTime
            << std::endl;
  std::cout << "speed: " << snake.Speed()
            << ", fixedFrameTime: " << fixedFrameTime << ", frame: " << frame
            << ", lastSnakeMoveFrame: " << lastSnakeMoveFrame << std::endl;
  moveStep = moveStep == 0 ? (int)(snake.Speed() * deltaFrame * fixedFrameTime)
                           : moveStep;
  std::cout << "moveStep: " << moveStep << std::endl;
  if (moveStep <= 0) {
    // 不能移动，什么都不做
    return;
  }

  for (int i = 0; i < moveStep; i++) {
    snake.Move();
    if (snake.CanEat(food)) {
      snake.Eat();
      GenFood();
    } else if (IsDie()) {
      Init();
      Game::Instance()->SwitchScene("gameover");
      return;
    }
  }

  lastSnakeMoveFrame = frame;
}

void MainScene::Rende() {
  BeginDrawing();
  ClearBackground(RAYWHITE);

  // map
  for (int x = 0; x < map.Cols(); x++) {
    for (int y = 0; y < map.Rows(); y++) {
      DrawRectangle(x * blockSize, y * blockSize, blockSize, blockSize,
                    LIGHTGRAY);
      DrawRectangleLines(x * blockSize, y * blockSize, blockSize, blockSize,
                         DARKGRAY);
    }
  }

  // food
  DrawRectangle((int)food.x * blockSize, (int)food.y * blockSize, blockSize,
                blockSize, SKYBLUE);

  // snake
  auto body = snake.Body();
  for (auto iter = body.begin(); iter != body.end(); iter++) {
    DrawRectangle(iter->x * blockSize, iter->y * blockSize, blockSize,
                  blockSize, PINK);
  }
  EndDrawing();
}

bool MainScene::IsDie() {
  auto head = snake.Body().begin();
  int x = (int)head->x;
  int y = (int)head->y;

  bool isOutMap = x < 0 || x >= map.Cols() || y < 0 || y >= map.Rows();
  if (isOutMap) {
    return true;
  }

  auto snakeHead = snake.Body().begin();
  if (snake.hasPos(*snakeHead)) {
    return true;
  }

  return false;
}

void MainScene::GenFood() {
  do {
    food.x = GetRandomValue(0, map.Cols() - 1);
    food.y = GetRandomValue(0, map.Rows() - 1);
  } while (snake.hasPos(food, false));
}
