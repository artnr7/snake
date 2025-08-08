#include "../include/model.h"

/** @brief  */

/** @brief Получение информации об игровой структуре */
GameInfo_t s21::Model::GetSInfo() { return s_info_; }

void s21::Model::ParseObjs() {
  ClearField();
  ParseSnake();
  ParseApple();
}

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
  for (int i = 0; i < FIELD_H; ++i) {
    for (int j = 0; j < FIELD_W; ++j) {
      s_info_.field[i][j] = PxCode::Nothing;
    }
  }
}

/** @brief Проходится в поле по кордам змейки и ставит соответствующий код в
 * ячейку поля */
void s21::Model::WalkOnSnake(PxCode &px_code) {
  auto it_e = (snake_anim_.GetBody()).end();
  for (auto it_b = snake_anim_.GetBody().begin(); it_b != it_e; ++it_b) {
    (s_info_.field)[(*it_b).cord_y_][(*it_b).cord_x_] = px_code;
  }
}

/*--------→ Score ← ---------*/
void s21::Model::IncreaseScore() { s_info_.score += 5; }

void s21::Model::SetSnakeDir(UserAction_t &action) {
  snake_anim_.SetDirection(action);
}

/*--------→ Collision ← ---------*/

void s21::Model::Collision() {
  WallCollision();
  SnakeSelfCollision();
}

void s21::Model::WallCollision() {

  auto head = snake_anim_.GetHead();

  if (head.cord_y_ < 0 || head.cord_y_ >= FIELD_H || head.cord_x_ < 0 ||
      head.cord_x_ >= FIELD_W) {
    s_info_.pause = GameState::GameOver;
  }
}

void s21::Model::SnakeSelfCollision() {
  if (s_info_.pause == GameState::GameOver ||
      s_info_.pause == GameState::Terminated)
    return;

  if (snake_anim_.CheckCollision()) {
    s_info_.pause = GameState::GameOver;
  }
}