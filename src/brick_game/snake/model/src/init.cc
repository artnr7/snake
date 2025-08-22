#include <iostream>

#include "../model.hpp"

s21::Model *s21::Model::model_ = nullptr;

/** @brief Геттер синглтона модели */
s21::Model *s21::Model::GetModel() {
  if (model_ == nullptr) {
    model_ = new Model();
  }
  return model_;
}

s21::Model::Model() : s_info_() {
  s_info_.pause = GameState::NoLaunched;
  s_info_.next = nullptr;
  Malloc();
}

void s21::Model::Malloc() {
  if (IsNoLaunched()) {
    s_info_.field = new int *[FIELD_H] {};

    for (int i = 0; i < FIELD_H; ++i) {
      (s_info_.field)[i] = new int[FIELD_W]{PxCode::NothingSnake};
    }
  }
}

/** @brief Инициализация игры */
void s21::Model::InitGame() {
  if (IsPaused()) {
    s_info_.pause = GameState::Launched;
  }
  if (!IsNoLaunched()) return;
  ParseSnake();
  SpawnApple();
  ParseApple();
  s_info_.pause = GameState::Launched;
  s_info_.speed = snake_anim_.GetSpeed();
  s_info_.high_score = GetHighscore();
}

/** @brief Постановка игры на паузу */
void s21::Model::TakeBreak() {
  if (IsLaunched()) {
    s_info_.pause = GameState::Paused;
  }
}

/** @brief Команда завершить игру и установить соответствующее состояние */
void s21::Model::GoEnd() {
  if (IsLaunched() || IsNoLaunched() || IsPaused()) {
    s_info_.pause = GameState::Terminated;
  }
}