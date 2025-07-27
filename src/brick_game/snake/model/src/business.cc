#include "model.h"

/** @brief  */

void s21::Model::Acceleration() {

  // наверное просто уменьшить таймер
}

void s21::Model::MoveSnake(UserAction_t &action) {
  ClearField();
  snake_anim_.SetDirection(action);
  snake_anim_.MoveBody();
  ParseSnake();

  EatApple();
  ParseApple();
}