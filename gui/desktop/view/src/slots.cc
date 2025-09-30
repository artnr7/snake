#include <iostream>

#include "../include/view.hpp"

/** @brief Обновление справочной информации */
void s21::GameWidget::UpdateInfo() { s21::GameWidget::UpdateInfoFun(); }

/** @brief Обновление модели */
void s21::GameWidget::BackUpdate() {
#ifdef SNAKE
  s21::Controller::userInput((UserAction_t)-1, false);
#elif TETRIS
  userInput((UserAction_t)-1, false);
#endif
}

/** @brief Передача сигнала модели */
void s21::GameWidget::TransmiteSignal(UserAction_t action, bool hold) {
#ifdef SNAKE
  s21::Controller::userInput(action, hold);
#elif TETRIS
  userInput(action, hold);
#endif
}
