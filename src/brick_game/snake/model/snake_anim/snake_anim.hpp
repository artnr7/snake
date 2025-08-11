#ifndef SNAKE_ANIM_H_
#define SNAKE_ANIM_H_

#include "../../data_types.h"
#include "../include/field_attr.h"
#include <deque>

#define SNAKE_INIT_SIZE 4
#define DEFAULT_SPEED 300
#define ACCELERATE_SPEED 75

namespace s21 {

typedef struct {
  int cord_y_ = 0;
  int cord_x_ = 0;
} ObjectPc;

typedef enum { Up, Right, Down, Left } SnakeDirection;

typedef struct {
  int default_speed;
  int acc_speed;
} SnakeSpeed;

class SnakeAnim {

public:
  SnakeAnim();
  const std::deque<ObjectPc> &GetBody();
  const ObjectPc GetHead();
  const int GetConstSpeed();
  int &GetSpeed();
  const int GetAccSpeed();

  void SetDirection(UserAction_t &action);
  void MoveBody();
  void RemoveTail();
  /*--------→ Speed ← ---------*/
  int CheckCollision();

private:
  std::deque<ObjectPc> body_;
  SnakeDirection s_dir_;
  SnakeSpeed speed_;
};
} // namespace s21

#endif