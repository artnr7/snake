#include "../include/snake_anim.h"

s21::SnakeAnim::SnakeAnim() : body_() {
  for (int i = 0; i < SNAKE_INIT_SIZE; ++i) {
    body_.push({FIELD_H_HALF, FIELD_W_HALF - i});
  }
}