#include "../include/model.h"
#include <iostream>

/** @brief  */

/** @brief Получение информации об игровой структуре */
GameInfo_t s21::Model::GetSInfo() { return s_info_; }

/** @brief  */
void s21::Model::ParseSnake() {
  if (s_info_.pause == GameState::GameOver ||
      s_info_.pause == GameState::Terminated)
    return;
  PxCode px_code = Snake;
  WalkOnSnake(px_code);
}

/** @brief  */
void s21::Model::ClearField() {
  PxCode px_code = Nothing;
  WalkOnSnake(px_code);
}

/** @brief Проходится в поле по кордам змейки и ставит соответствующий код в
 * ячейку поля */
void s21::Model::WalkOnSnake(PxCode &px_code) {
  auto it_e = (snake_anim_.GetBody()).end();
  for (auto it_b = snake_anim_.GetBody().begin(); it_b != it_e; ++it_b) {
    (s_info_.field)[(*it_b).cord_y_][(*it_b).cord_x_] = px_code;
  }
}

void s21::Model::WallCollision() {

  auto head = snake_anim_.GetHead();

  if (head.cord_y_ < 0 || head.cord_y_ >= FIELD_H || head.cord_x_ < 0 ||
      head.cord_x_ >= FIELD_W) {
    s_info_.pause = GameState::GameOver;
  }
}

/*--------→ Score ← ---------*/
void s21::Model::IncreaseScore() { ++s_info_.score; }