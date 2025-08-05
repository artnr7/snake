#include "../include/model.h"

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
  s_info_.field[apple_.cord_y_][apple_.cord_x_] = PxCode::Apple;
}

/** @brief  */
void s21::Model::EatApple() {
  auto head = *(snake_anim_.GetBody().begin());
  if (head.cord_y_ == apple_.cord_y_ && head.cord_x_ == apple_.cord_x_) {
    SpawnApple();
    IncreaseScore();
  }
}