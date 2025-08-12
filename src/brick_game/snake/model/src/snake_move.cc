#include "../include/model.hpp"

/*=====================→  ←==================== */
/** @brief  */

void s21::Model::MoveSnake(bool &dly) {
  if (dly) {
    snake_anim_.MoveBody();
  }
}

void s21::Model::RemoveOrNotTail(bool &ate_apple, bool &dly) {
  if (!ate_apple && dly) {
    snake_anim_.RemoveTail();
  }
}