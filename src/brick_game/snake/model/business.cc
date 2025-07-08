#include "model.h"

void s21::Model::Acceleration() {}

void s21::Model::GoStraight() {
  ClearField();
  snake_anim_.StraightShift();
  ParseSnake();

  EatApple();
  ParseApple();
}

void s21::Model::TurnLeft() {
  ClearField();
  snake_anim_.StraightShift();
  ParseSnake();

  EatApple();
  ParseApple();
}