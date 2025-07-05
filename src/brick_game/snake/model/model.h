#ifndef MODEL_H_
#define MODEL_H_

#include "../data_types.h"
#include "config.h"
#include "objects/include/apple.h"
#include "objects/include/snake_anim.h"

namespace s21 {
class Model {

protected:
  Model();

  static Model *model_;
  /*=====================→ VARIABLES ←==================== */
  GameInfo_t s_info_;
  Apple apple_;
  SnakeAnim snake_anim_;

public:
  /*=====================→ METHODS ←==================== */

  static Model *GetModel();
  void Malloc();
  // не нужен void Mdealloc();
  /*=====================→ BUSINESS ←==================== */
  void GoStraight();
  void TurnLeft();
  void TurnRight();
  void Acceleration();
};
} // namespace s21

#endif