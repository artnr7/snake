#include "controller.hpp"

#include "../model/model.hpp"
#ifdef CLI
#include "controller_wrapper_for_c.h"
#endif

/** @brief Обёртка над Си++ для использования в Си-проектах */
#ifdef CLI
/** @brief Геттер для создания статического объекта для обёртки Си */
s21::Controller *s21::Controller::GetController() {
  static Controller st_controller;
  return &st_controller;
}

/** @brief Ввод игрока */
void userInput(UserAction_t action, bool hold) {
  return s21::Controller::GetController()->userInput(action, hold);
}

/** @brief Получение переменных игры существующих в данный момент */
GameInfo_t updateCurrentState() {
  return s21::Controller::GetController()->updateCurrentState();
}
#endif

/** @brief Ввод игрока */
void s21::Controller::userInput(UserAction_t action, bool hold) {
  s21::Model *model = s21::Model::GetModel();

  model->GameStep();
  switch (action) {
    case UserAction_t::Start:
      model->InitGame();
      break;
    case UserAction_t::Pause:
      model->TakeBreak();
      break;
    case UserAction_t::Terminate:
      model->GoEnd();
      break;
    case UserAction_t::Up:
      model->SetSnakeDir(action);
      break;
    case UserAction_t::Right:
      model->SetSnakeDir(action);
      break;
    case UserAction_t::Down:
      model->SetSnakeDir(action);
      break;
    case UserAction_t::Left:
      model->SetSnakeDir(action);
      break;
    case UserAction_t::Action:
      model->ChangeSpeed(hold);
      break;
  }
}

/** @brief Получение переменных игры существующих в данный момент */
GameInfo_t s21::Controller::updateCurrentState() {
  s21::Model *model = s21::Model::GetModel();
  return model->GetSInfo();
}