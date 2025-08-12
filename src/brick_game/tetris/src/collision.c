#include "../include/collision.h"

/** @brief Находится ли блок в границах поля
 * @note Используется в основном чтобы обезопасить процесс обращения к элементу
 * игрового поля по индексу
 */
bool is_blk_insd(int i, int j) {
  return (i >= 0 && i < FLD_H) && (j >= 0 && j < FLD_W);
}

/** @brief Определение может ли тетромино вращаться
 * @details В цикле мы проверяем можем ли мы копировать тетромино в новое место,
 * если хоть один блок не может быть скопирован значит ставим статус, что мы
 * пытаемся сдвинуть наш блок
 * Также если место куда мы пытаемся скопировать находится ниже нижней границы
 * поля, значит мы не пытаемся сдвинуть наш тетромино и повернуть мы его не
 * можем
 * @bug На самом деле проверка может ли тетромино повернуться после сдвига нет,
 * она косвенная
 */
void can_tmino_rot_fn(GameInfo_t g_info, int i, int j, int rot_mtx_h,
                      int rot_mtx_w, bool *try_x_mv, bool *can_tmino_rot) {
  int blk_qty = 0;  // ◄ кол-во пройденных блоков тетромино, в каждом 4

  /* k и l соответствующие индексы, куда копируем блоки */
  for (int k = i; k < rot_mtx_h && blk_qty <= TMINO_BLKS_QTY; k++) {
    for (int l = j; l < rot_mtx_w && blk_qty <= TMINO_BLKS_QTY; l++) {
      int rot_mtx_i =
          rot_mtx_h - (l - j) - 1;  // ◄ верт. индекс откуда копируем
      int rot_mtx_j = j + k - i;  // ◄ горизонтальный индекс откуда копируем

      if (is_blk_insd(rot_mtx_i, rot_mtx_j) &&
          mvg_px_dtrm(g_info.field[rot_mtx_i][rot_mtx_j])) {
        if (!is_blk_insd(k, l) ||
            (is_blk_insd(k, l) && stc_px_dtrm(g_info.field[k][l]))) {
          *try_x_mv = true;
        }
        *can_tmino_rot = k >= FLD_H ? false : *can_tmino_rot;
        *try_x_mv = *can_tmino_rot ? *try_x_mv : false;

        blk_qty++;
      }
    }
  }
}

/** @brief Коллизия с нижней границей поля
 * @note Проверяет находится ли тетромино рядом с нижней границей
 * @return Упадёт ли тетромино в следующем кадре
 */
bool bot_coll(GameInfo_t g_info) {
  int blk_qty = 0;  // ◄ кол-во пройденных блоков тетромино, в каждом их 4
  bool tmino_will_fall = false;  // ◄ упадёт ли тетромино в следующем кадре

  for (int i = 0; i < FLD_H && blk_qty <= TMINO_BLKS_QTY; i++) {
    for (int j = 0; j < FLD_W && blk_qty <= TMINO_BLKS_QTY; j++) {
      if (mvg_px_dtrm(g_info.field[i][j])) {
        /* ▼ Коллизия с нижней границей поля */
        if (i == FLD_H - 1 ||
            (is_blk_insd(i + 1, j) && stc_px_dtrm(g_info.field[i + 1][j]))) {
          tmino_will_fall = true;
        }
        blk_qty++;
      }
    }
  }
  return tmino_will_fall;
}

/** @brief Коллизия с левой и правой границами поля и тетромино */
void lr_brd_tmino_coll(const GameInfo_t *g_info,
                       WhoIsNearby_t *who_is_nearby) {
  int blk_qty = 0;  // ◄ кол-во пройденных блоков тетромино, в каждом их 4

  for (int i = 0; i < FLD_H && blk_qty <= TMINO_BLKS_QTY; i++) {
    for (int j = 0; j < FLD_W && blk_qty <= TMINO_BLKS_QTY; j++) {
      if (mvg_px_dtrm(g_info->field[i][j])) {
        /* ▼ Коллизия с левой и правой границами поля */
        if (j == 0) {
          who_is_nearby->LBorder = true;
        } else if (j == FLD_W - 1) {
          who_is_nearby->RBorder = true;
        }
        /* ▼ Коллизия с тетромино */
        if (is_blk_insd(i, j - 1) && stc_px_dtrm(g_info->field[i][j - 1])) {
          who_is_nearby->LBlock = true;
        }
        if (is_blk_insd(i, j + 1) && stc_px_dtrm(g_info->field[i][j + 1])) {
          who_is_nearby->RBlock = true;
        }

        blk_qty++;
      }
    }
  }
}

/** @brief Указание возможности движения влево-вправо для блока тетромино */
void can_tmino_mv_fn(WhoIsNearby_t who_is_nearby,
                     CanTetrominoMove_t *can_tmino_mv) {
  if (who_is_nearby.LBorder) {
    *can_tmino_mv = ToRight;  // ◄ разрешение движения вправо
    if (who_is_nearby.RBlock) {
      *can_tmino_mv = NoWay;  // ◄ запрет движения
    }
  } else if (who_is_nearby.RBorder) {
    *can_tmino_mv = ToLeft;  // ◄ разрешение движения влево
    if (who_is_nearby.LBlock) {
      *can_tmino_mv = NoWay;  // ◄ запрет движения
    }
  } else if (who_is_nearby.LBlock) {
    *can_tmino_mv = ToRight;  // ◄ разрешение движения вправо
    if (who_is_nearby.RBlock) {
      *can_tmino_mv = NoWay;  // ◄ запрет движения
    }
  }
}