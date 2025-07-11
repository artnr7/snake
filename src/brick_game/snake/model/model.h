#ifndef MODEL_H_
#define MODEL_H_

#include "../data_types.h"
#include "field_attr.h"
#include "objects/include/object.h"
#include "objects/snake_anim.h"
#include <random>

namespace s21 {
class Model {

protected:
  Model();

  static Model *model_;
  /*=====================→ VARIABLES ←==================== */
  GameInfo_t s_info_;
  ObjectPc apple_;
  SnakeAnim snake_anim_;

  /*=====================→ METHODS ←==================== */
  void Malloc();
  void ParseApple();
  void ParseSnake();
  void SpawnApple();
  void EatApple();

  void ClearField();

  void WalkOnSnake(PxCode &px_code);

  /*--------→ Score ← ---------*/
  void IncreaseScore();

public:
  /*=====================→ METHODS ←==================== */

  static Model *GetModel();
  // не нужен void Mdealloc();
  /*=====================→ BUSINESS ←==================== */
  void GoEnd();
  void TakeABreak();
  void MoveSnake(UserAction_t &action);
  void Acceleration();
  GameInfo_t GetSInfo();
};
} // namespace s21

#endif