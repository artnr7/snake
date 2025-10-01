#include "../model.hpp"

/** @brief Движение змейки если задержка позволяет */
void s21::Model::MoveSnake(bool &dly) {
  if (dly) {
    snake_anim_.MoveBody();
  }
}

/** @brief Решение убирать ли хвост у змейки в этом кадре */
void s21::Model::RemoveOrNotTail(bool &ate_apple, bool &dly) {
  if (!ate_apple && dly) {
    snake_anim_.RemoveTail();
  }
}