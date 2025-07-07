#include "../include/snake_anim.h"

s21::SnakeAnim::SnakeAnim() : body_() {
  for (int i = 0; i < SNAKE_INIT_SIZE; ++i) {
    body_.push_back({(PxCode)1, FIELD_H_HALF, FIELD_W_HALF - i});
  }
}

const std::vector<s21::ObjectPc> &s21::SnakeAnim::GetBody() { return body_; }

void s21::SnakeAnim::StraightShift() {

  for (auto it_e = body_.rbegin(); it_e + 1 != body_.rend(); ++it_e) {

    *it_e = *(it_e + 1);
  }

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
    break;
  }
}