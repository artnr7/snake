#ifndef SNAKE_ANIM_H_
#define SNAKE_ANIM_H_

#include "object.h"
#include <vector>

#define SNAKE_INIT_SIZE 4

namespace s21 {

class SnakeAnim : public Object {

public:
  SnakeAnim();
  const std::vector<ObjectPc> &GetBody();

  void StraightShift();

private:
  std::vector<ObjectPc> body_;
};
} // namespace s21

#endif