#ifndef SNAKE_ANIM_H_
#define SNAKE_ANIM_H_

#include "object.h"
#include <deque>

#define SNAKE_INIT_SIZE 4

namespace s21 {

class SnakeAnim : public Object {

public:
  SnakeAnim();
  const std::deque<ObjectPc> &GetBody();

  void StraightShift();
  void LeftShift();

private:
  std::deque<ObjectPc> body_;
  SnakeDirection snake_direction_;
};
} // namespace s21

#endif