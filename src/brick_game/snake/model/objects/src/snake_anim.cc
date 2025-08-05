#include "../include/snake_anim.h"

s21::SnakeAnim::SnakeAnim() : body_() {
  for (int i = 0; i < SNAKE_INIT_SIZE; ++i) {
    body_.push_back({FIELD_H_HALF, FIELD_W_HALF - i});
  }
  s_dir_ = SnakeDirection::Right;
}

const std::deque<s21::ObjectPc> &s21::SnakeAnim::GetBody() { return body_; }

void s21::SnakeAnim::MoveBody() {
  auto head = *body_.begin();

  switch (s_dir_) {
  case Up:
    ++(head.cord_y_);
    break;
  case Right:
    ++(head.cord_x_);
    break;
  case Down:
    --(head.cord_y_);
    break;
  case Left:
    --(head.cord_x_);
  }

  body_.pop_back();
  body_.push_front({head});
}

void s21::SnakeAnim::SetDirection(UserAction_t &action) {

  switch (action) {
  case UserAction_t::Up:
    if (s_dir_ == SnakeDirection::Left || s_dir_ == SnakeDirection::Right)
      s_dir_ = SnakeDirection::Up;
    break;
  case UserAction_t::Right:
    if (s_dir_ == SnakeDirection::Left || s_dir_ == SnakeDirection::Right)
      s_dir_ = SnakeDirection::Right;
    break;
  case UserAction_t::Left:
    if (s_dir_ == SnakeDirection::Left || s_dir_ == SnakeDirection::Right)
      s_dir_ = SnakeDirection::Left;
    break;
  case UserAction_t::Down:
    if (s_dir_ == SnakeDirection::Left || s_dir_ == SnakeDirection::Right)
      s_dir_ = SnakeDirection::Down;
    break;
  }
}