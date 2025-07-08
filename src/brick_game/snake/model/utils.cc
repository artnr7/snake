#include "model.h"

GameInfo_t s21::Model::GetSInfo() { return s_info_; }

void s21::Model::ParseApple() {
  s_info_.field[apple_.cord_y_][apple_.cord_x_] = PxCode::Apple;
}

void s21::Model::ParseSnake() {
  PxCode px_code = Snake;
  WalkOnSnake(px_code);
}

void s21::Model::ClearField() {
  PxCode px_code = Nothing;
  WalkOnSnake(px_code);
}

void s21::Model::SpawnApple() {

  std::random_device rd;
  std::mt19937 rng(rd());

  std::uniform_int_distribution<int> y_dist(0, FIELD_H - 1);
  std::uniform_int_distribution<int> x_dist(0, FIELD_W - 1);

  do {
    apple_.cord_y_ = y_dist(rng);
    apple_.cord_x_ = x_dist(rng);
  } while ((s_info_.field)[apple_.cord_y_][apple_.cord_x_] != PxCode::Nothing);
}

void s21::Model::EatApple() {
  auto head = *(snake_anim_.GetBody().begin());
  if (head.cord_y_ == apple_.cord_y_ && head.cord_x_ == apple_.cord_x_) {
    SpawnApple();
    IncreaseScore();
  }
}

void s21::Model::WalkOnSnake(PxCode &px_code) {
  auto it_e = (snake_anim_.GetBody()).end();
  for (auto it_b = snake_anim_.GetBody().begin(); it_b != it_e; ++it_b) {
    (s_info_.field)[(*it_b).cord_y_][(*it_b).cord_x_] = px_code;
  }
}

/*--------→ Score ← ---------*/
void s21::Model::IncreaseScore() { ++s_info_.score; }