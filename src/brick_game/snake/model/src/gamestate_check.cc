#include "../include/model.h"

bool s21::Model::IsNoLaunched() {
  return s_info_.pause == GameState::NoLaunched;
}

bool s21::Model::IsLanchedOrPaused() {
  return s_info_.pause == GameState::Launched ||
         s_info_.pause == GameState::Paused;
}

bool s21::Model::IsGameoverOrTerminated() {
  return s_info_.pause == GameState::GameOver ||
         s_info_.pause == GameState::Terminated;
}

bool s21::Model::IsGameEnd() { return IsGameoverOrTerminated(); }