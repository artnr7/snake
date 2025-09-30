#include "../model.hpp"

/** @brief Находится ли игра в состянии Запущенном */
bool s21::Model::IsLaunched() { return s_info_.pause == GameState::Launched; }

/** @brief Находится ли игра в состянии Незапущенная */
bool s21::Model::IsNoLaunched() {
  return s_info_.pause == GameState::NoLaunched;
}

/** @brief Находится ли игра в состянии Паузы */
bool s21::Model::IsPaused() { return s_info_.pause == GameState::Paused; }