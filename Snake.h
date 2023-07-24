#pragma once

#include <list>
#include <raylib.h>

class Snake {
public:
  enum Direction { UP, RIGHT, DOWN, LEFT, UNKNOWN = 100 };

  // 初始化长度为1， 位置为中间
  Snake(const Vector2 &pos);

  // 在重新游戏时，初始化长度为1
  void ReInit(const Vector2 &pos);

  const std::list<Vector2> &Body();

  void Move();

  bool SetDirection(Direction direction);

  bool CanEat(const Vector2 &pos);
  void Eat();

  double Speed();
  void SetSpeed(double speed);

  bool hasPos(const Vector2 &pos, bool excludeHead = true);

private:
  void MoveAfterEating();
  void MoveWithoutEating();
  void UpdateMovePos();

private:
  std::list<Vector2> body;
  Direction direction;
  bool eating;
  double speed; // n格/ms
};
