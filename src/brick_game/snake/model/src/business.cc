#include "../model.hpp"

/** @brief Шаг игры
 * @details Сборник функций выполняющихся при каждом вызове обновления
 * контроллера
 */
void s21::Model::GameStep() {
  if (!IsLaunched()) {
    return;
  }

  bool dly = MoveDelay();

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
  snake_anim_.SetDirection(action);
}