#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include "../../data_types/data_types.h"
namespace s21 {
class Controller {
 protected:
  Controller() {};

 public:
#ifdef CLI
  /** @brief Геттер для создания статического объекта для обёртки Си */
  static Controller *GetController();
#endif
  /*=====================→ METHODS ←==================== */
  /** @brief Ввод игрока */
  static void userInput(UserAction_t action, bool hold);

  /** @brief Получение переменных игры существующих в данный момент */
  static GameInfo_t updateCurrentState();
};
}  // namespace s21

#endif