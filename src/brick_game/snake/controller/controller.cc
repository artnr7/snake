#include "controller.h"
#include <iostream>

s21::Controller::Controller() {}

// void s21::Controller::GameLoop(UserAction_t action, bool hold) {
//   s21::Model *model = s21::Model::GetModel();

//   while (model) {
//     userInput(action, hold);
//   }
// }

// s21::Controller *s21::Controller::GetController() {
//   if (controller_ == nullptr) {
//     controller_ = new Controller();
//   }
//   return controller_;
// }

void s21::Controller::userInput(UserAction_t action, bool hold) {
  s21::Model *model = s21::Model::GetModel();

  switch (action) {
  case UserAction_t::Start:
    model->InitGame();
    break;
  case UserAction_t::Pause:
    model->TakeABreak();
    break;
  case UserAction_t::Terminate:
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
  case UserAction_t::Action:
    if (hold) {
      model->Acceleration();
    } else {
      model->Slowdown();
    }
    break;
  default:
    model->DelayMoveSnake();
    break;
  }
}

GameInfo_t s21::Controller::updateCurrentState() {
  s21::Model *model = s21::Model::GetModel();
  return model->GetSInfo();
}