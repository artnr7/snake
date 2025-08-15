#include "../include/model.hpp"

bool s21::Model::IsLaunched() { return s_info_.pause == GameState::Launched; }

bool s21::Model::IsNoLaunched() {
  return s_info_.pause == GameState::NoLaunched;
}

bool s21::Model::IsPaused() { return s_info_.pause == GameState::Paused; }

bool s21::Model::IsLanchedOrPaused() { return IsLaunched() || IsPaused(); }

bool s21::Model::IsGameoveredOrTerminated() {
  return s_info_.pause == GameState::GameOvered ||
         s_info_.pause == GameState::Terminated;
}

bool s21::Model::IsGameEnd() { return IsGameoveredOrTerminated(); }

bool s21::Model::IsGameInactive() { return 0; }