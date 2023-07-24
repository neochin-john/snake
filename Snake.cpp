#include "Snake.h"
#include <raylib.h>

// 初始化长度为1， 位置为中间
Snake::Snake(const Vector2 &pos) { ReInit(pos); }

// 在重新游戏时，初始化长度为1
void Snake::ReInit(const Vector2 &pos) {
  body.resize(1);
  auto head = body.begin();
  head->x = pos.x;
  head->y = pos.y;

  direction = RIGHT;
  eating = false;

  speed = 0.002; // 1s下降2格
}

// 返回头迭代，使用head->next()找到下一部分身体，直到nullptr
const std::list<Vector2> &Snake::Body() { return body; }

void Snake::UpdateMovePos() {
  auto head = body.begin();
  switch (direction) {
  case UP:
    head->y--;
    break;
  case RIGHT:
    head->x++;
    break;
  case DOWN:
    head->y++;
    break;
  case LEFT:
    head->x--;
    break;
  default:
    break;
  }
}

void Snake::MoveAfterEating() {
  UpdateMovePos();
  eating = false;
}

void Snake::MoveWithoutEating() {
  auto head = body.begin();
  Vector2 newHead = {head->x, head->y};
  body.push_front(newHead);
  body.pop_back();
  UpdateMovePos();
}

void Snake::Move() {
  if (!eating) {
    MoveWithoutEating();
  } else {
    MoveAfterEating();
  }
}

bool Snake::SetDirection(Direction direction) {
  int isOriginalVertical = this->direction == UP || this->direction == DOWN;
  int isSetDirectionVertical = direction == UP || direction == DOWN;
  // 同方向上不能改方向
  if (isOriginalVertical xor isSetDirectionVertical) {
    this->direction = direction;
    return true;
  }

  return false;
}

bool Snake::CanEat(const Vector2 &pos) {
  auto head = body.begin();
  return ((int)head->x) == ((int)pos.x) && ((int)head->y == (int)pos.y);
}

void Snake::Eat() {
  eating = true;
  auto head = body.begin();
  Vector2 newHead = {head->x, head->y};
  body.push_front(newHead);
}

double Snake::Speed() { return speed; }

void Snake::SetSpeed(double speed) { this->speed = speed; }

bool Snake::hasPos(const Vector2 &pos, bool excludeHead) {
  auto iter = body.begin();
  if (excludeHead) {
    iter++;
  }

  for (; iter != body.end(); iter++) {
    if ((int)iter->x == (int)pos.x && (int)iter->y == (int)pos.y) {
      return true;
    }
  }

  return false;
}
