#include "../include/view.hpp"
#include <iostream>

void s21::GameWidget::Exit() {
  GameInfo_t g_info = {};

#ifdef TETRIS
  g_info = updateCurrentState();
  static int flag = 0;
  if (g_info.field != NULL) {
    flag = 1;
  }

  if (g_info.field == NULL && flag == 1) {
    exit(1);
  }
#elif SNAKE
  g_info = s21::Controller::updateCurrentState();
  if (g_info.pause == GameState::GameOver) {
    exit(1);
  }
  if (g_info.pause == GameState::Terminated) {
    exit(2);
  }
#endif
}

void s21::GameWidget::UpdateInfo() { s21::GameWidget::UpdateInfoFun(); }

void s21::GameWidget::BackUpdate() {

#ifdef SNAKE
  s21::Controller::userInput((UserAction_t)-1, false);
#elif TETRIS
  userInput(UserAction_t(-1), false);
#endif
}

void s21::GameWidget::TransmiteSignal(UserAction_t action, bool hold) {
#ifdef SNAKE
  s21::Controller::userInput(action, hold);
#elif TETRIS
  userInput(action, hold);
#endif
}
