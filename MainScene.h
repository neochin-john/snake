#pragma once

#include "Mat2D.h"
#include "Scene.h"
#include "Snake.h"

class MainScene : public Scene {
public:
  MainScene(int mapRows, int mapCols);
  void Init();
  void Update() override;
  void Rende() override;

private:
  bool IsDie();
  void GenFood();

  Vector2 food;
  Mat2D map;
  Snake snake;

  int lastSnakeMoveFrame;

  int blockSize;
};
