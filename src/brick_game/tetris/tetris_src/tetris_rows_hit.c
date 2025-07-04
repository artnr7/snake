#include "../tetris_include/tetris_rows_hit.h"

/** @brief Уничтожение полных рядов */
void rows_hit(GameInfo_t *tg_info) {
  int ersd_rows_qty = 0;  // ◄ кол-во уничтоженных рядов
  int full_row_i = 0;     // ◄ кол-во полных рядов

  /* Пока есть полные ряды, они уничтожаются;
   * После схлопываются верхняя и
   * нижняя границы, также увеличивается счётчик, уничтоженных рядов
   ▼ */
  while (is_row_compl(*tg_info, &full_row_i)) {
    tmino_collapse(tg_info, full_row_i);
    ersd_rows_qty++;
  }
  /* После того как все полные ряды уничтожены на основе кол-ва уничтоженных за
   * одно выполнение функции рядов начисляется определённое кол-во очков
   * игроку
   * ▼ */
  scr_chg(tg_info, ersd_rows_qty);
}

/** @brief Проверка является ли ряд полным
 * @details Проходимся по рядам поля, если кол-во статических блоков равно
 * ширине поля значит ряд заполнен, записываем его номер и выходим
 */
bool is_row_compl(GameInfo_t tg_info, int *full_row_i) {
  bool is_row_compl = false;
  for (int i = 0; i < FLD_H && !is_row_compl; i++) {
    int stc_qty = 0;
    for (int j = 0; j < FLD_W; j++) {
      if (stc_px_dtrm(tg_info.field[i][j])) {
        stc_qty++;
      }
    }
    if (stc_qty == FLD_W) {
      *full_row_i = i;
      is_row_compl = true;
    }
  }
  return is_row_compl;
}

/** @brief Схлопывание верхней и нижней частей после уничтожения ряда*/
void tmino_collapse(GameInfo_t *tg_info, int full_row_i) {
  int **nxt_frm = fld_nxt_frm(0);

  /* ▼ Перерисовывание нижней части поля */
  for (int i = full_row_i + 1; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      nxt_frm[i][j] = tg_info->field[i][j];
    }
  }
  /* ▼ Перерисовывание верхней части поля */
  for (int i = 0; i < full_row_i; i++) {
    for (int j = 0; j < FLD_W; j++) {
      nxt_frm[i + 1][j] = tg_info->field[i][j];
    }
  }

  fld_cp(tg_info->field, nxt_frm);
}

/** @brief Изменение счёта игрока, в зависимости от уничтоженных за один раз
 * рядов */
void scr_chg(GameInfo_t *tg_info, int ersd_rows_qty) {
  switch (ersd_rows_qty) {
    case (1):
      tg_info->score += OneLine;
      break;
    case (2):
      tg_info->score += TwoLines;
      break;
    case (3):
      tg_info->score += ThreeLines;
      break;
    case (4):
      tg_info->score += FourLines;
  }
}