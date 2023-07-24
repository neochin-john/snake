#pragma once

class Scene {
public:
  virtual void Update() = 0;
  virtual void Rende() = 0;
  void SetFrame(int frame) { this->frame = frame; }

protected:
  int frame;
};
