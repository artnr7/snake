#include "../include/view.h"

void s21::GameWidget::Exit() {
  GameInfo_t g_info = {};

#ifdef TETRIS
  g_info = updateCurrentState();
#elif SNAKE
  g_info = s21::Controller::updateCurrentState();
  // std::cout << s21::Controller::updateCurrentState().pause << " ";
#endif
  if (g_info.pause == GameState::GameOver) {
    exit(1);
  }
  if (g_info.pause == GameState::Terminated) {
    exit(2);
  }
}

void s21::GameWidget::UpdateInfo() { s21::GameWidget::UpdateInfoFun(); }

void s21::GameWidget::BackUpdate() {
  s21::Controller::userInput((UserAction_t)-1, false);
}

void s21::GameWidget::TransmiteSignal(UserAction_t action, bool hold) {
  s21::Controller::userInput(action, hold);
}
