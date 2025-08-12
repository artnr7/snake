#include "../include/model.hpp"
#include <iostream>

/*=====================→ INIT ←==================== */

/** @brief  */

s21::Model *s21::Model::model_ = nullptr;

s21::Model *s21::Model::GetModel() {
  if (model_ == nullptr) {
    model_ = new Model();
  }
  return model_;
}

s21::Model::Model() : s_info_() {
  Malloc();
  s_info_.pause = GameState::NoLaunched;
}

void s21::Model::Malloc() {
  if (!s_info_.field) {
    s_info_.field = new int *[FIELD_H] {};

    for (int i = 0; i < FIELD_H; ++i) {
      (s_info_.field)[i] = new int[FIELD_W]{PxCode::Nothing};
    }
  }
}

void s21::Model::InitGame() {
  if (IsLanchedOrPaused())
    return;
  ParseSnake();
  SpawnApple();
  ParseApple();
  s_info_.pause = GameState::Launched;
  s_info_.speed = snake_anim_.GetSpeed();
  s_info_.high_score = GetHighscore();
}

void s21::Model::TakeBreak() { s_info_.pause = GameState::Paused; }

void s21::Model::GoEnd() { s_info_.pause = GameState::Terminated; }

// не нужен
// void s21::Model::Mdealloc() {
//   if (s_info_.field != nullptr) {
//     for (int i = 0; i < FIELD_H; ++i) {
//       delete[] (s_info_.field)[i];
//     }
//     delete[] s_info_.field;
//   }
// }
