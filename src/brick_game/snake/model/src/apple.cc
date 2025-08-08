#include "../include/model.h"
#include <random>

/** @brief Спавн яблока в случайной свободной ячейке поля
 * @todo Когда больше не будет свободной ячейки игра должна завершаться
 */
void s21::Model::SpawnApple() {

  std::random_device rd;
  std::mt19937 rng(rd());

  std::uniform_int_distribution<int> y_dist(0, FIELD_H - 1);
  std::uniform_int_distribution<int> x_dist(0, FIELD_W - 1);

  do {
    apple_.cord_y_ = y_dist(rng);
    apple_.cord_x_ = x_dist(rng);
  } while ((s_info_.field)[apple_.cord_y_][apple_.cord_x_] != PxCode::Nothing);
  /* пока по этим кордам в поле не будет пустоты ↑ */
}

/** @brief  */
void s21::Model::ParseApple() {
  if (s_info_.pause == GameState::GameOver ||
      s_info_.pause == GameState::Terminated)
    return;
  s_info_.field[apple_.cord_y_][apple_.cord_x_] = PxCode::Apple;
}

/** @brief  */
int s21::Model::EatApple() {
  if (IsGameEnd())
    return 0;

  bool ate_apple = 0;
  auto head = snake_anim_.GetHead();
  if (head.cord_y_ == apple_.cord_y_ && head.cord_x_ == apple_.cord_x_) {
    SpawnApple();
    IncreaseScore();
    LevelUp();
    SetSnakeSpeed();
    GetConstSnakeSpeed();
    ate_apple = 1;
  }

  return ate_apple;
}