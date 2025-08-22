#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "../../data_types/data_types.h"
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
};
}  // namespace s21

#endif