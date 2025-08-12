#include "../include/model.hpp"

// #ifdef CLI
// #include "gamestate_check_wrapper_for_c.h"

// bool IsNoLaunched() { return s21::Controller::IsNoLauched(); }
// bool IsLanchedOrPaused() { return s21::Controller::IsLanchedOrPaused(); }
// bool IsGameoverOrTerminated() {
//   return s21::Controller::IsGameoverOrTerminated();
// }
// bool IsGameEnd() { return s21::Controller::IsGameEnd(); }
// #endif

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