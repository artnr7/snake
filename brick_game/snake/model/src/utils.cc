#include "../model.hpp"

#define PointReward 1

/** @brief Геттер структуры переменных игры существующих в данный момент */
GameInfo_t s21::Model::GetSInfo() { return s_info_; }

/** @brief Парсинг объектор в поле */
void s21::Model::ParseObjs() {
  if (!IsLaunched()) return;
  ClearField();
  ParseSnake();
  ParseApple();
}

/** @brief Парсинг змейки в поле */
void s21::Model::ParseSnake() {
  if (!IsLaunched()) return;
  PxCode px_code = Snake;
  WalkOnSnake(px_code);
}

/** @brief Очищение поля для последующего парсинга */
void s21::Model::ClearField() {
  if (!IsLaunched()) return;
  for (int i = 0; i < FIELD_H; ++i) {
    for (int j = 0; j < FIELD_W; ++j) {
      s_info_.field[i][j] = PxCode::NothingSnake;
    }
  }
}

/** @brief Проходится в поле по кордам змейки и ставит соответствующий код в
 * ячейку поля */
void s21::Model::WalkOnSnake(PxCode &px_code) {
  if (!IsLaunched()) return;
  auto it_e = (snake_anim_.GetBody()).end();
  for (auto it_b = snake_anim_.GetBody().begin(); it_b != it_e; ++it_b) {
    (s_info_.field)[(*it_b).cord_y_][(*it_b).cord_x_] = px_code;
  }
}

/*--------→ Score ← ---------*/
/** @brief Увеличение счёта */
void s21::Model::IncreaseScore() {
  if (!IsLaunched()) return;
  s_info_.score += PointReward;
}

/** @brief Установление статуса игры как Выигранная */
void s21::Model::Win() {
  if (!IsLaunched()) return;

  if (s_info_.score == MAX_SCORE) {
    s_info_.pause = GameState::Woned;
  }
}

/*--------→ Collision ← ---------*/
/** @brief Коллизия со стенами и змейки с самой собой */
void s21::Model::Collision() {
  if (!IsLaunched()) return;
  WallCollision();
  SnakeSelfCollision();
}

/** @brief Коллизия со стеной */
void s21::Model::WallCollision() {
  if (!IsLaunched()) return;
  auto head = snake_anim_.GetHead();

  if (head.cord_y_ < 0 || head.cord_y_ >= FIELD_H || head.cord_x_ < 0 ||
      head.cord_x_ >= FIELD_W) {
    s_info_.pause = GameState::GameOvered;
  }
}

/** @brief Коллизия змейки с самой собой */
void s21::Model::SnakeSelfCollision() {
  if (!IsLaunched()) return;
  if (snake_anim_.CheckCollision()) {
    s_info_.pause = GameState::GameOvered;
  }
}