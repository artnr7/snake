#include "../../include/moving/rotate.h"

/** @brief Функция действия, когда пользователь нажимает ДЕЙСТВИЕ
 * @note Схема такая: в функции нахождаются i и j первого попавшегося блока,
 * являющегося двигаемым блоком, после от него через функцию определенную для
 * каждой фигуры высчитывается размер и начальные координаты вращательной
 * матрицы
 * Вращательная матрица - матрица, которая описывает фигуру по её размеру для
 * вращения вокруг оси
 * Например:
 * вокруг I опишется матрица 4x4, в рамках которой и будет происходить движение
 * ┌────┐
 * │....│
 * │■■■■│
 * │....│
 * │....│
 * └────┘ */
void tmino_spin(GameInfo_t *g_info, int *pos, bool *tmino_fell) {
  /* ▼ Чтобы не двигалось при паузе */
  if (is_inactive(g_info)) {
    return;
  }
  int **nxt_frm = fld_nxt_frm(0);
  fld_mvg_nthg_cp(g_info->field, nxt_frm);

  bool try_x_mv = false; // ◄ пытаемся ли подвинуть тетромино по горизонтали
  bool can_tmino_rot = true; // ◄ может ли тетромино крутиться
  int fst_blk_i = 0, fst_blk_j = 0;
  fst_mvg_blk_find(*g_info, &fst_blk_i, &fst_blk_j, &can_tmino_rot);

  /* ▼ Объявление и начальная инициализация размеров вращательной матрицы */
  int rot_mtx_h = 3, rot_mtx_w = 3;
  rot_mtx(g_info->field[fst_blk_i][fst_blk_j], pos, &fst_blk_i, &fst_blk_j,
          &rot_mtx_h, &rot_mtx_w);

  can_tmino_rot_fn(*g_info, fst_blk_i, fst_blk_j, rot_mtx_h, rot_mtx_w,
                   &try_x_mv, &can_tmino_rot);

  /* ▼ Если тетромино рядом с нижней границей тетромино не может крутиться */
  can_tmino_rot = can_tmino_rot ? !bot_coll(*g_info) : can_tmino_rot;

  tmino_way_decis(g_info, nxt_frm, fst_blk_i, fst_blk_j, rot_mtx_h, rot_mtx_w,
                  try_x_mv, pos, tmino_fell, can_tmino_rot);
}

/** @brief Нахождение первого движущегося блока тетромино в поле и запрет
 * вращения если тетромино оказалось квадратом */
void fst_mvg_blk_find(GameInfo_t g_info, int *fst_blk_i, int *fst_blk_j,
                      bool *can_tmino_rot) {
  bool braek = false; // ◄ выход из цикла после нахождения блока

  for (int i = 0; i < FIELD_H && braek == false; i++) {
    for (int j = 0; j < FIELD_W && braek == false; j++) {
      if (mvg_px_dtrm(g_info.field[i][j])) {
        if (g_info.field[i][j] == MagentaOMvg) {
          *can_tmino_rot = false;
        }
        *fst_blk_i = i;
        *fst_blk_j = j;
        braek = true;
      }
    }
  }
}

/** @brief Решение что делать с тетромино */
void tmino_way_decis(GameInfo_t *g_info, int **nxt_frm, int i, int j,
                     int rot_mtx_h, int rot_mtx_w, bool try_x_mv, int *pos,
                     bool *tmino_fell, bool can_tmino_rot) {
  /* Если тетромино может двигаться */
  if (can_tmino_rot) {
    /* Если тетромино не нужно двигаться по горизонтали чтобы вращаться,
     значит вращаем его
     ▼ */
    if (!try_x_mv) {
      tmino_rot(g_info, nxt_frm, i, j, rot_mtx_h, rot_mtx_w);
      *pos = (*pos + 1) % TMINO_POS_QTY; // ◄ при вращ. поза меняется на след.
      fld_cp(g_info->field, nxt_frm);
    }
    /* Если тетромино нужно двигаться по горизонтали чтобы вращаться, значит
       пытаемся сдвинуться
       ▼ */
    else {
      tmino_shift_rot(g_info, j, pos, tmino_fell, &can_tmino_rot);
    }
  }
}

/** @brief Вращение тетромино
 * @warning Вызывать только если уверены, что тетромино может вращаться */
void tmino_rot(GameInfo_t *g_info, int **nxt_frm, int i, int j, int rot_mtx_h,
               int rot_mtx_w) {
  /* k и l соответствующие индексы, куда копируем блоки */
  for (int k = i; k < rot_mtx_h; k++) {
    for (int l = j; l < rot_mtx_w; l++) {
      int rot_mtx_i = rot_mtx_h - (l - j) - 1; // ◄ верт. индекс откуда копируем
      int rot_mtx_j = j + k - i; // ◄ горизонтальный индекс откуда копируем

      if (is_blk_insd(rot_mtx_i, rot_mtx_j) &&
          mvg_px_dtrm(g_info->field[rot_mtx_i][rot_mtx_j])) {
        nxt_frm[k][l] = g_info->field[rot_mtx_i][rot_mtx_j];
      }
    }
  }
}

/** @brief Вращение тетромино с попыткой сдвига
 * @details Исходя из того, на какой половине игрового поля находится тетромино
 * решаем куда пытатемся сдвинуть тетромино, если тетромино сдвигается
 * вызываем функцию Действия(то есть получается рекурсия)
 * @bug По идее проверки получится ли повернуть тетромино после сдвига нет,
 * поэтому возможен такой сценарий при котором тетромино сдвинется, но не
 * повернётся
 */
void tmino_shift_rot(GameInfo_t *g_info, int j, int *pos, bool *tmino_fell,
                     bool *can_tmino_rot) {
  int lr_way = 0;
  if (j > FIELD_W_HALF) { // ◄ правая половина
    lr_way = Left;
  } else if (j <= FIELD_W_HALF) { // ◄ левая половина
    lr_way = Right;
  }

  if (lr_mv(g_info, lr_way)) {
    tmino_spin(g_info, pos, tmino_fell);
  } else {
    *can_tmino_rot = false;
  }
}

/** @brief Вызов, исходя из того какой вид тетромино вращается, функций
 нахождения координаты в поле, от которой строится вращательная матрица */
void rot_mtx(int px, const int *pos, int *i, int *j, int *rot_mtx_h,
             int *rot_mtx_w) {
  switch (px) {
  case RedIMvg:
    red_i_rot(pos, i, j);
    *rot_mtx_h += 1;
    *rot_mtx_w += 1;
    break;
  case GreenLMvg:
    green_l_rot(pos, i, j);
    break;
  case YellowZMvg:
    yellow_z_rot(pos, i, j);
    break;
  case BlueJMvg:
    blue_j_rot(pos, i, j);
    break;
  case CyanSMvg:
    cyan_s_rot(pos, i, j);
    break;
  case WhiteTMvg:
    white_t_rot(pos, i, j);
  }
  /* Прибавляем к размеру вращательной матрицы координаты первого движущегося
   * блока
   ▼ */
  *rot_mtx_h += *i;
  *rot_mtx_w += *j;
}

/** @brief Нахождение координат от которых строится вращательная матрица для
 * тетромино I */
void red_i_rot(const int *pos, int *i, int *j) {
  switch (*pos) {
  case 0:
    *i -= 1;
    /* ▲
     * ┌────┐
     * │....│
     * │■■■■│
     * │....│
     * │....│
     * └────┘ */
    break;
  case 1:
    *j -= 2;
    /* ▲
     * ┌────┐
     * │..■.│
     * │..■.│
     * │..■.│
     * │..■.│
     * └────┘ */
    break;
  case 2:
    *i -= 2;
    /* ▲
     * ┌────┐
     * │....│
     * │....│
     * │■■■■│
     * │....│
     * └────┘ */
    break;
  case 3:
    *j -= 1;
    /* ▲
     * ┌────┐
     * │.■..│
     * │.■..│
     * │.■..│
     * │.■..│
     * └────┘ */
  }
}

/** @brief Нахождение координат от которых строится вращательная матрица для
 * тетромино L*/
void green_l_rot(const int *pos, int *i, int *j) {
  switch (*pos) {
  case 0:
    *j -= 2;
    /* ▲
     * ┌───┐
     * │..■│
     * │■■■│
     * │...│
     * └───┘ */
    break;
  case 1:
    *j -= 1;
    /* ▲
     * ┌───┐
     * │.■.│
     * │.■.│
     * │.■■│
     * └───┘ */
    break;
  case 2:
    *i -= 1;
    /* ▲
     * ┌───┐
     * │...│
     * │■■■│
     * │■..│
     * └───┘ */
    break;
  case 3:
    // ничего не делаем, совпадает
    /* ▲
     * ┌───┐
     * │■■.│
     * │.■.│
     * │.■.│
     * └───┘ */
  }
}

/** @brief Нахождение координат от которых строится вращательная матрица для
 * тетромино Z */
void yellow_z_rot(const int *pos, int *i, int *j) {
  switch (*pos) {
  case 0:
    // ничего не делаем, совпадает
    /* ▲
     * ┌───┐
     * │■■.│
     * │.■■│
     * │...│
     * └───┘ */
    break;
  case 1:
    *j -= 2;
    /* ▲
     * ┌───┐
     * │..■│
     * │.■■│
     * │.■.│
     * └───┘ */
    break;
  case 2:
    *i -= 1;
    /* ▲
     * ┌───┐
     * │...│
     * │■■.│
     * │.■■│
     * └───┘ */
    break;
  case 3:
    *j -= 1;
    /* ▲
     * ┌───┐
     * │.■.│
     * │■■.│
     * │■..│
     * └───┘ */
  }
}

/** @brief Нахождение координат от которых строится вращательная матрица для
 * тетромино J */
void blue_j_rot(const int *pos, int *i, int *j) {
  switch (*pos) {
  case 0:
    // ничего не делаем, совпадает
    /* ▲
     * ┌───┐
     * │■..│
     * │■■■│
     * │...│
     * └───┘ */
    break;
  case 1:
    *j -= 1;
    /* ▲
     * ┌───┐
     * │.■■│
     * │.■.│
     * │.■.│
     * └───┘ */
    break;
  case 2:
    *i -= 1;
    /* ▲
     * ┌───┐
     * │...│
     * │■■■│
     * │..■│
     * └───┘ */
    break;
  case 3:
    *j -= 1;
    /* ▲
     * ┌───┐
     * │.■.│
     * │.■.│
     * │■■.│
     * └───┘ */
  }
}

/** @brief Нахождение координат от которых строится вращательная матрица для
 * тетромино S */
void cyan_s_rot(const int *pos, int *i, int *j) {
  switch (*pos) {
  case 0:
    *j -= 1;
    /* ▲
     * ┌───┐
     * │.■■│
     * │■■.│
     * │...│
     * └───┘ */
    break;
  case 1:
    *j -= 1;
    /* ▲
     * ┌───┐
     * │.■.│
     * │.■■│
     * │..■│
     * └───┘ */
    break;
  case 2:
    *i -= 1;
    *j -= 1;
    /* ▲
     * ┌───┐
     * │...│
     * │.■■│
     * │■■.│
     * └───┘ */
    break;
  case 3:
    // ничего не делаем, совпадает
    /* ▲
     * ┌───┐
     * │.■.│
     * │.■■│
     * │..■│
     * └───┘ */
  }
}

/** @brief Нахождение координат от которых строится вращательная матрица для
 * тетромино T */
void white_t_rot(const int *pos, int *i, int *j) {
  switch (*pos) {
  case 0:
    *i -= 1;
    *j -= 1;
    /* ▲
     * ┌───┐
     * │...│
     * │.■.│
     * │■■■│
     * └───┘ */
    break;
  case 1:
    // ничего не делаем, совпадает
    /* ▲
     * ┌───┐
     * │■..│
     * │■■.│
     * │■..│
     * └───┘ */
    break;
  case 2:
    // ничего не делаем, совпадает
    /* ▲
     * ┌───┐
     * │■■■│
     * │.■.│
     * │...│
     * └───┘ */
    break;
  case 3:
    *j -= 2;
    /* ▲
     * ┌───┐
     * │..■│
     * │.■■│
     * │..■│
     * └───┘ */
  }
}
