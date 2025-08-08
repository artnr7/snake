#include "controller.h"
#include <iostream>

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

GameInfo_t s21::Controller::updateCurrentState() {
  s21::Model *model = s21::Model::GetModel();
  return model->GetSInfo();
}