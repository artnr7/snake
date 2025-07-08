#ifndef SNAKE_ANIM_H_
#define SNAKE_ANIM_H_

#include "../../data_types.h"
#include "object_attr.h"
#include <deque>

#define SNAKE_INIT_SIZE 4

namespace s21 {

using cord = int;

typedef struct {
  cord cord_y_ = 0;
  cord cord_x_ = 0;
} ObjectPc;

class SnakeAnim {

public:
  SnakeAnim();
  const std::deque<ObjectPc> &GetBody();

  void SetDirection(UserAction_t &action);
  void MoveBody();

private:
  std::deque<ObjectPc> body_;
  SnakeDirection snake_direction_;
};
} // namespace s21

#endif