#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../data_types.h"
#include "../model/model.h"

namespace s21 {
class Controller {

public:
  Controller();

  void userInput(UserAction_t action, bool hold) ;
  GameInfo_t updateCurrentState() {}
};
} // namespace s21

#endif