#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../data_types.h"
#include "../model/include/model.h"

namespace s21 {
class Controller {

protected:
  Controller();

  // static Controller *controller_;

public:
  /*=====================→ METHODS ←==================== */
  static void userInput(UserAction_t action, bool hold);
  static GameInfo_t updateCurrentState();

  // void GameLoop(UserAction_t action, bool hold);

  // static Controller *GetController();
};
} // namespace s21

#endif