#include "../include/model.h"

/** @brief  */
void s21::Model::Acceleration() { s_info_.speed = snake_anim_.GetAccSpeed(); }

void s21::Model::Slowdown() { s_info_.speed = snake_anim_.GetSpeed(); }

void s21::Model::MoveSnake(UserAction_t &action) {
  if (s_info_.pause == GameState::NoLaunched)
    return;
  ClearField();
  snake_anim_.SetDirection(action);
  snake_anim_.MoveBody();
  WallCollision();

  ParseSnake();

  EatApple();
  ParseApple();

  SnakeSpeed();
}

void s21::Model::DelayMoveSnake() {
  if (SnakeSpeed()) {
    UserAction_t temp = (UserAction_t)-1;
    MoveSnake(temp);
  }
}
