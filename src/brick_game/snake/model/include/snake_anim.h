#ifndef SNAKE_ANIM_H_
#define SNAKE_ANIM_H_

#include "object.h"
#include <queue>

#define SNAKE_INIT_SIZE 4

namespace s21 {
class SnakeAnim : public Object {
public:
  SnakeAnim();

private:
  std::queue<ObjectPc> body_;
};
} // namespace s21

#endif