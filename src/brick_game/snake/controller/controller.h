#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../data_types.h"
#include "../model/include/model.h"

namespace s21 {
class Controller {

public:
  Controller();

  static void userInput(UserAction_t action, bool hold);
  GameInfo_t updateCurrentState();

  void GameLoop(UserAction_t action, bool hold);
};
} // namespace s21

#endif