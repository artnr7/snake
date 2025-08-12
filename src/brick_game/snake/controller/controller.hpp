#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../model/include/model.hpp"

namespace s21 {
class Controller {

protected:
  Controller() {};

public:
#ifdef CLI
  static Controller *GetController();
#endif
  /*=====================→ METHODS ←==================== */
  static void userInput(UserAction_t action, bool hold);
  static GameInfo_t updateCurrentState();

  // static bool IsNoLaunched();
  // static bool IsLanchedOrPaused();
  // static bool IsGameoverOrTerminated();
  // static bool IsGameEnd();
};
} // namespace s21

#endif