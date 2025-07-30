#include "../include/snake_anim.h"

s21::SnakeAnim::SnakeAnim() : body_() {
  for (int i = 0; i < SNAKE_INIT_SIZE; ++i) {
    body_.push_back({FIELD_H_HALF, FIELD_W_HALF - i});
  }
}

const std::deque<s21::ObjectPc> &s21::SnakeAnim::GetBody() { return body_; }

void s21::SnakeAnim::MoveBody() {
  body_.pop_back();
  body_.push_front({*body_.begin()});

  auto head = *body_.begin();

  switch (snake_direction_) {
  case Up:
    ++head.cord_y_;
    break;
  case Right:
    ++head.cord_x_;
    break;
  case Down:
    --head.cord_y_;
    break;
  case Left:
    --head.cord_x_;
  }
}

void s21::SnakeAnim::SetDirection(UserAction_t &action) {
  switch (action) {
  case UserAction_t::Up:
    snake_direction_ = SnakeDirection::Up;
    break;
  case UserAction_t::Right:
    snake_direction_ = SnakeDirection::Right;
    break;
  case UserAction_t::Left:
    snake_direction_ = SnakeDirection::Left;
    break;
  case UserAction_t::Down:
    snake_direction_ = SnakeDirection::Down;
    break;
  }
}