#include "../../include/moving/moving_utils.h"

/** @brief Проверка является ли пиксель движущимся */
bool mvg_px_dtrm(PixelCode_t px) {
  return px == RedIMvg || px == GreenLMvg || px == YellowZMvg ||
         px == BlueJMvg || px == MagentaOMvg || px == CyanSMvg ||
         px == WhiteTMvg;
}

/** @brief Проверка является ли пиксель статичным */
bool stc_px_dtrm(PixelCode_t px) {
  return px == RedIStc || px == GreenLStc || px == YellowZStc ||
         px == BlueJStc || px == MagentaOStc || px == CyanSStc ||
         px == WhiteTStc;
}

/** @brief В поле А копируется поле B (A ← B) полностью */
void fld_cp(int **field, int **nxt_frm) {
  for (int i = 0; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      field[i][j] = nxt_frm[i][j];
    }
  }
}

/** @brief В nxt_frm копируется field (nxt_frm ← field) всё, кроме движущегося
 */
void fld_mvg_nthg_cp(int **field, int **nxt_frm) {
  for (int i = 0; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      nxt_frm[i][j] = Nothing;
      if (!mvg_px_dtrm(field[i][j])) {
        nxt_frm[i][j] = field[i][j];
      }
    }
  }
}
