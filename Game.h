#pragma once
#include <map>
#include <string>

#include "Scene.h"

class Game {
public:
  Game();
  void SetFixedFrameTime(double fixedFrameTime);
  double FixedFrameTime();
  void AddScene(std::string name, Scene &scene);
  void Run();

  void SwitchScene(std::string name);
  void SetScreenSize(int width, int height);
  int ScreenWidth();
  int ScreenHeight();

  static Game *Instance();

private:
  std::map<std::string, Scene &> scenes;
  std::string activeSceneName;
  Scene *activeScene = nullptr;

  static Game *gameInstance;
  double fixedFrameTime; // milliseconds

  int screenWidth;
  int screenHeight;
};
