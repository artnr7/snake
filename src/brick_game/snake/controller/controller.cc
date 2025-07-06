#include "controller.h"

s21::Controller::Controller() {}

void s21::Controller::userInput(UserAction_t action, bool hold) {

  s21::Model *model = s21::Model::GetModel();

  switch (action) {
  case Start:
    //  итак создаём
    break;
  case Pause:
    model->TakeABreak();
    break;
  case Terminate:
    model->GoEnd();
    break;
  case Left:
    model->TurnLeft();
    break;
  case Right:
    model->TurnRight();
    break;
  case Action:
    model->Acceleration();
    break;

  default:
    model->GoStraight();
    break;
  }
}