#include <random>

#include "../model.hpp"

/** @brief Спавн яблока в случайной свободной ячейке поля
 * @todo Когда больше не будет свободной ячейки игра должна завершаться */
void s21::Model::SpawnApple() {
  if (!IsLaunched()) return;
  if (s_info_.score == MAX_SCORE) {
    return;
  }
  std::random_device rd;
  std::mt19937 rng(rd());

  std::uniform_int_distribution<int> y_dist(0, FIELD_H - 1);
  std::uniform_int_distribution<int> x_dist(0, FIELD_W - 1);

  do {
    apple_.cord_y_ = y_dist(rng);
    apple_.cord_x_ = x_dist(rng);
  } while ((s_info_.field)[apple_.cord_y_][apple_.cord_x_] !=
           PxCode::NothingSnake);
/* пока по этим кордам в поле не будет пустоты ↑ */
#ifdef TEST
  static int i = 0;
  if (i == 0) {
    apple_.cord_y_ = FIELD_H_HALF;
    apple_.cord_x_ = FIELD_W_HALF + 1;
  } else if (i == 1) {
    apple_.cord_y_ = FIELD_H_HALF + 1;
    apple_.cord_x_ = FIELD_W_HALF + 1;
  } else if (i == 2) {
    apple_.cord_y_ = FIELD_H_HALF + 1;
    apple_.cord_x_ = FIELD_W_HALF;
  }
  ++i;
#endif
}

/** @brief Парсинг яблока в поле */
void s21::Model::ParseApple() {
  if (!IsLaunched()) return;
  s_info_.field[apple_.cord_y_][apple_.cord_x_] = PxCode::Apple;
}

/** @brief Проверка ест ли змейка яблоко */
int s21::Model::EatApple() {
  if (!IsLaunched()) {
    return 0;
  }
  bool ate_apple = 0;
  auto head = snake_anim_.GetHead();
  if (head.cord_y_ == apple_.cord_y_ && head.cord_x_ == apple_.cord_x_) {
    IncreaseScore();
    SpawnApple();
    LevelUp();
    SetSnakeSpeed();
    GetConstSnakeSpeed();
    ate_apple = 1;
  }

  return ate_apple;
}