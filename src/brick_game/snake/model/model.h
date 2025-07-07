#ifndef MODEL_H_
#define MODEL_H_

#include "../data_types.h"
#include "field_attr.h"
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
  int **next_frame;

  /*=====================→ METHODS ←==================== */
  void Malloc();
  void ParseObj();
  void RespawnApple();

public:
  /*=====================→ METHODS ←==================== */

  static Model *GetModel();
  // не нужен void Mdealloc();
  /*=====================→ BUSINESS ←==================== */
  void GoEnd();
  void TakeABreak();
  void GoStraight();
  void TurnLeft();
  void TurnRight();
  void Acceleration();
};
} // namespace s21

#endif