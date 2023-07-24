#include "Game.h"

#include <iostream>

Game *Game::gameInstance = new Game();

Game *Game::Instance() { return gameInstance; }

Game::Game() {
  scenes.clear();
  fixedFrameTime = .0;
}

void Game::SetFixedFrameTime(double fixedFrameTime) {
  this->fixedFrameTime = fixedFrameTime;
}

double Game::FixedFrameTime() { return fixedFrameTime; }

void Game::AddScene(std::string name, Scene &scene) {
  bool isFirst = scenes.size() == 0;
  scenes.insert({name, scene});
  if (isFirst) {
    activeSceneName = name;
    activeScene = &scenes.at(name);
  }
}

void Game::Run() {
  activeScene->Update();
  activeScene->Rende();
}

void Game::SwitchScene(std::string name) {
  activeSceneName = name;
  activeScene = &scenes.at(name);
  activeScene->SetFrame(0);
  std::cout << "SwitchScene: " << name << std::endl;
}

void Game::SetScreenSize(int width, int height) {
  screenWidth = width;
  screenHeight = height;
}

int Game::ScreenWidth() { return screenWidth; }
int Game::ScreenHeight() { return screenHeight; }
