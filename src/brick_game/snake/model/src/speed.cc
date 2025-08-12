#include "../include/model.hpp"
#define DEFAULT_SNAKE_SPEED DEFAULT_SPEED
#define SNAKE_SPEED_MULT 20

void s21::Model::ChangeSpeed(bool &hold) {
  if (hold) {
    GetAccSpeed();
  } else {
    GetConstSnakeSpeed();
  }
}

void s21::Model::GetAccSpeed() { s_info_.speed = snake_anim_.GetAccSpeed(); }

void s21::Model::GetConstSnakeSpeed() {
  s_info_.speed = snake_anim_.GetConstSpeed();
}

void s21::Model::SetSnakeSpeed() {
  snake_anim_.GetSpeed() =
      DEFAULT_SNAKE_SPEED - s_info_.level * SNAKE_SPEED_MULT;
}
