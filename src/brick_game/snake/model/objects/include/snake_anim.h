#ifndef SNAKE_ANIM_H_
#define SNAKE_ANIM_H_

#include "../../../data_types.h"
#include "../../include/field_attr.h"
#include "object_conf.h"
#include <deque>

#define SNAKE_INIT_SIZE 4

namespace s21 {

typedef enum { Up, Right, Down, Left } SnakeDirection;

class SnakeAnim {

public:
  SnakeAnim();
  const std::deque<ObjectPc> &GetBody();
  const ObjectPc GetHead();

  void SetDirection(UserAction_t &action);
  void MoveBody();

private:
  std::deque<ObjectPc> body_;
  SnakeDirection s_dir_;
};
} // namespace s21

#endif