#include "../model.hpp"
UserAction_t s21::Model::buffer_ = UserAction_t::Start;

/** @brief Шаг игры
 * @details Сборник функций выполняющихся при каждом вызове обновления
 * контроллера
 */
void s21::Model::GameStep() {
  if (!IsLaunched()) {
    return;
  }

  bool dly = MoveDelay();

  SetSnakeDir();

  MoveSnake(dly);

  bool ate_apple = EatApple();

  RemoveOrNotTail(ate_apple, dly);

  SetHighscore();

  Collision();

  Win();

  ParseObjs();
}

void s21::Model::SetSnakeDir(UserAction_t &action) {
  if (!IsLaunched()) return;
  buffer_ = action;
}

void s21::Model::SetSnakeDir() {
  if (!IsLaunched()) return;
  snake_anim_.SetDirection(buffer_, skip_buffer_further_);
}