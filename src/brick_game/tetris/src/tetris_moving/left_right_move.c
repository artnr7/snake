#include "../../include/moving/left_right_move.h"

/** @brief Движение тетромино влево-вправо
 * @return Сдвинулся ли тетромино
 */
bool lr_mv(GameInfo_t *g_info, UserAction_t action) {
  int **nxt_frm = fld_nxt_frm(0);

  fld_mvg_nthg_cp(g_info->field, nxt_frm);
  CanTetrominoMove_t can_tmino_mv = NoWay;

  /* ▼ Выдаём возможность движения в соотвествии с командой */
  if (action == Left) {
    can_tmino_mv = ToLeft;
  } else if (action == Right) {
    can_tmino_mv = ToRight;
  }

  WhoIsNearby_t who_is_nearby = {0};
  /* ▼ Проходимся по матрице чтобы узнать какие соседи есть у тетромино */
  lr_brd_tmino_coll(g_info, &who_is_nearby);

  /* ▼ Исходя из того какие есть соседы указываем возможность для движения */
  can_tmino_mv_fn(who_is_nearby, &can_tmino_mv);

  bool mvd = false; // ◄ сдвинулся тетромино или нет

  lr_shift(*g_info, nxt_frm, action, can_tmino_mv, &mvd);

  fld_cp(g_info->field, nxt_frm);
  return mvd;
}

/** @brief Смещение тетромино в соответствующую сторону  */
void lr_shift(GameInfo_t g_info, int **nxt_frm, UserAction_t action,
              CanTetrominoMove_t can_tmino_mv, bool *mvd) {
  int blk_qty = 0; // ◄ кол-во пройденных блоков тетромино, в каждоме их 4

  for (int i = 0; i < FIELD_H && blk_qty <= TMINO_BLKS_QTY; i++) {
    for (int j = 0; j < FIELD_W && blk_qty <= TMINO_BLKS_QTY; j++) {
      if (mvg_px_dtrm(g_info.field[i][j])) {
        int x_shift = j; // ◄ смещение по горизонтали

        /* Если команда и разрешение движения совпадают переменная сдвига
         * меняется соответственно
         ▼ */
        if (action == Left && can_tmino_mv == ToLeft) {
          x_shift--;
          *mvd = true;
        } else if (action == Right && can_tmino_mv == ToRight) {
          x_shift++;
          *mvd = true;
        }

        /* ▼ Чтобы не двигалось при паузе */
        if (is_paused(&g_info)) {
          x_shift = j;
        }
        /* ▼ Cамо смещение в указанную сторону */
        nxt_frm[i][x_shift] = g_info.field[i][j];

        blk_qty++;
      }
    }
  }
}
