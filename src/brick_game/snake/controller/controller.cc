#include "controller.h"

s21::Controller::Controller() {}

void s21::Controller::GameLoop(UserAction_t action, bool hold) {
  s21::Model *model = s21::Model::GetModel();

  while (model) {
    userInput(action, hold);
  }
}

void s21::Controller::userInput(UserAction_t action, bool hold) {
  s21::Model *model = s21::Model::GetModel();

  switch (action) {
  case Start:
    s21::Model::GetModel();
    break;
  case Pause:
    model->TakeABreak();
    break;
  case Terminate:
    model->GoEnd();
    break;
  case UserAction_t::Up:
    model->MoveSnake(action);
    break;
  case UserAction_t::Right:
    model->MoveSnake(action);
    break;
  case UserAction_t::Down:
    model->MoveSnake(action);
    break;
  case UserAction_t::Left:
    model->MoveSnake(action);
    break;
  case Action:
    model->Acceleration();
    break;

  default:
    model->MoveSnake(action);
    break;
  }
}

GameInfo_t s21::Controller::updateCurrentState() {
  s21::Model *model = s21::Model::GetModel();
  return model->GetSInfo();
}