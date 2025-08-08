#include "../include/model.h"

/*=====================→ BUSINESS ←==================== */
/** @brief  */

void s21::Model::GameStep() {
  if (IsNoLaunched())
    return;
  bool dly = MoveDelay();

  MoveSnake(dly);

  bool ate_apple = EatApple();

  RemoveOrNotTail(ate_apple, dly);

  SetHighscore();

  Collision();

  ParseObjs();
}