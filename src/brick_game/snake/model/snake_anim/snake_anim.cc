#include "snake_anim.h"
#include <iostream>

s21::SnakeAnim::SnakeAnim() : body_() {
  for (int i = 0; i < SNAKE_INIT_SIZE; ++i) {
    body_.push_back({FIELD_H_HALF, FIELD_W_HALF - i});
  }
  s_dir_ = SnakeDirection::Right;

  speed_.default_speed = DEFAULT_SPEED;
  speed_.acc_speed = ACCELERATE_SPEED;
}

const std::deque<s21::ObjectPc> &s21::SnakeAnim::GetBody() { return body_; }

const s21::ObjectPc s21::SnakeAnim::GetHead() { return *body_.begin(); }

void s21::SnakeAnim::MoveBody() {
  auto new_head = GetHead();

  switch (s_dir_) {
  case Up:
    --(new_head.cord_y_);
    break;
  case Right:
    ++(new_head.cord_x_);
    break;
  case Down:
    ++(new_head.cord_y_);
    break;
  case Left:
    --(new_head.cord_x_);
  }

  body_.push_front({new_head});
}

int s21::SnakeAnim::CheckCollision() {
  auto head = GetHead();
  int flag = 0;
  for (auto it_b = body_.begin() + 1; it_b != body_.end(); ++it_b) {
    if (head.cord_y_ == (*it_b).cord_y_ && head.cord_x_ == (*it_b).cord_x_) {
      flag = 1;
    }
  }
  return flag;
}

void s21::SnakeAnim::RemoveTail() { body_.pop_back(); }

void s21::SnakeAnim::SetDirection(UserAction_t &action) {

  switch (action) {
  case UserAction_t::Up:
    if (s_dir_ == SnakeDirection::Left || s_dir_ == SnakeDirection::Right) {
      s_dir_ = SnakeDirection::Up;
    }
    break;
  case UserAction_t::Right:
    if (s_dir_ == SnakeDirection::Up || s_dir_ == SnakeDirection::Down) {
      s_dir_ = SnakeDirection::Right;
    }
    break;
  case UserAction_t::Down:
    if (s_dir_ == SnakeDirection::Left || s_dir_ == SnakeDirection::Right) {
      s_dir_ = SnakeDirection::Down;
    }
    break;
  case UserAction_t::Left:
    if (s_dir_ == SnakeDirection::Up || s_dir_ == SnakeDirection::Down) {
      s_dir_ = SnakeDirection::Left;
    }
  }
}

const int s21::SnakeAnim::GetConstSpeed() { return speed_.default_speed; }

int &s21::SnakeAnim::GetSpeed() { return speed_.default_speed; }

const int s21::SnakeAnim::GetAccSpeed() { return speed_.acc_speed; }