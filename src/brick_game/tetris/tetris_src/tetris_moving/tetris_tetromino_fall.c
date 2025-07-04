#include "../../tetris_include/tetris_moving/tetris_tetromino_fall.h"

/** @brief Падение тетромино с задержкой
 * @details Если задержка(dly) накопилась и больше игровой скорости, то
 * тетромино падает
 */
void tmino_fall_with_dly(GameInfo_t *tg_info, bool *tmino_fell, long int dly) {
  if (dly > tg_info->speed) {
    tmino_fall(tg_info, tmino_fell);
  }
}

/** @brief Случайное падение тетромино, при других действиях пользователя,
 * связанных с перемещением
 * @details Нужна чтобы при спаме действий тетромино продолжало падать, а не
 * становилось заложником других действий
 */
void rand_fall(GameInfo_t *tg_info, UserAction_t action, long int dly,
               bool *tmino_fell) {
  int fall_freq = rand() % 60;
  if ((action == Left || action == Right || action == Action) && fall_freq) {
    tmino_fall_with_dly(tg_info, tmino_fell, dly);
  }
}

/** @brief Падение тетромино
 * @details Не делает что-то конкретное, вызывает вспомогательные функции чтобы
 * произвести падение тетромино, напрямую не вызывается потому что нет
 * возможности регулировать "скорость падения"
 */
void tmino_fall(GameInfo_t *tg_info, bool *tmino_fell) {
  /* ▼ Чтобы не двигалось при паузе */
  if (tg_info->pause == 1) {
    return;
  }
  int **nxt_frm = fld_nxt_frm(0);

  fld_mvg_nthg_cp(tg_info->field, nxt_frm);

  *tmino_fell = bot_coll(*tg_info);

  down_shift(tg_info->field, nxt_frm, *tmino_fell);

  tmino_fixation(nxt_frm, *tmino_fell);

  fld_cp(tg_info->field, nxt_frm);
}

/** @brief Смещение вниз
 * @details Ищем движущиеся блоки, если блок не находится у нижней
 * границы (tmino_fell == false), то смещение становится = 1 (shift_y = 1), и
 * блок падает
 * @param tmino_fell Упала/упадёт тетромино в следующем кадре
 */
void down_shift(int **field, int **nxt_frm, bool tmino_fell) {
  int blk_qty =
      0;  // ◄ кол-во пройденных блоков тетромино, в каждой фигуре их 4

  for (int i = 0; i < FLD_H && blk_qty <= TMINO_BLKS_QTY; i++) {
    for (int j = 0; j < FLD_W && blk_qty <= TMINO_BLKS_QTY; j++) {
      if (mvg_px_dtrm(field[i][j])) {
        int shift_y = 0;

        /* ▼ Если не будем падать, то сдвига вертикального нет */
        if (!tmino_fell) {
          shift_y = 1;
        }

        nxt_frm[i + shift_y][j] = field[i][j];
        blk_qty++;
      }
    }
  }
}

/** @brief Фиксация движущихся блоков на месте превращением их в статические
 * @details Если тетромино находится у нижней границы, и должно "упасть" и
 * (tmino_fell == true) значит мы фиксируем блоки, превращаем их в статические
 */
void tmino_fixation(int **nxt_frm, bool tmino_fell) {
  if (!tmino_fell) {
    return;
  }
  int blk_qty = 0;  // ◄ кол-во пройденных блоков тетромино, в каждом 4

  for (int i = 0; i < FLD_H && blk_qty <= TMINO_BLKS_QTY; i++) {
    for (int j = 0; j < FLD_W && blk_qty <= TMINO_BLKS_QTY; j++) {
      if (nxt_frm[i][j] == RedIMvg) {
        nxt_frm[i][j] = RedIStc;
      } else if (nxt_frm[i][j] == GreenLMvg) {
        nxt_frm[i][j] = GreenLStc;
      } else if (nxt_frm[i][j] == YellowZMvg) {
        nxt_frm[i][j] = YellowZStc;
      } else if (nxt_frm[i][j] == BlueJMvg) {
        nxt_frm[i][j] = BlueJStc;
      } else if (nxt_frm[i][j] == MagentaOMvg) {
        nxt_frm[i][j] = MagentaOStc;
      } else if (nxt_frm[i][j] == CyanSMvg) {
        nxt_frm[i][j] = CyanSStc;
      } else if (nxt_frm[i][j] == WhiteTMvg) {
        nxt_frm[i][j] = WhiteTStc;
      }
      if (mvg_px_dtrm(nxt_frm[i][j])) {
        blk_qty++;
      }
    }
  }
}

/** @brief Падение тетромино до самой нижней возможной в нынешнем положении
 * границы
 * @details Циклически вызывается функция падения тетромино, до тех пор пока оно
 * не упадёт
 */
void action_down_fn(GameInfo_t *tg_info, bool *tmino_fell) {
  for (int i = 0; i < FLD_H && !(*tmino_fell); i++) {
    tmino_fall(tg_info, tmino_fell);
  }
}
