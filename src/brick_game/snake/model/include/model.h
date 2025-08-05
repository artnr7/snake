#ifndef MODEL_H_
#define MODEL_H_

#include "../../data_types.h"
#include "field_attr.h"
// #include "objects/include/object.h"
#include "../objects/include/snake_anim.h"
#include <random>

namespace s21 {

typedef enum { Nothing, Apple, Snake } PxCode;

typedef enum { NoLaunched, Launched, Paused, Terminated } GameState;

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
  void ParseSnake();

  /*--------→ Apple ← ---------*/
  void ParseApple();
  void SpawnApple();
  void EatApple();

  void ClearField();

  void WalkOnSnake(PxCode &px_code);

  /*--------→ Score ← ---------*/
  void IncreaseScore();

public:
  /*=====================→ METHODS ←==================== */
  void InitGame();

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