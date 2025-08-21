#include "test_utils.h"

#include "../brick_game/tetris/tetris_include/tetris_moving/tetris_moving_utils.h"

void chess_fill(int **field) {
  for (int i = 0; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      field[i][j] = RedIStc;
      if (i % 10 == j) {
        field[i][j] = Nothing;
      }
    }
  }
}

void fill(int **field, int qty) {
  if (qty < 1)
    return;
  for (int i = FLD_H - qty; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      field[i][j] = RedIStc;
    }
  }
}

/** 0 moving
 * 1 static */
int move_detect(int **field, const Tetromino_t tmino, int st_y, int st_x,
                int mode) {
  wchar_t ch = L'♥';
  int str_i = 0, y = st_y, x = st_x, blks = 0;
  bool spc_skip = false;

  while (ch != '\0') {
    ch = tmino.shape[str_i++];
    /* Когда мы видим первый пробел, то прибавляем координату по y, и не
     * прибавляем до тех пор пока пробелы не закончатся и будет какой-нибудь
     * другой символ
     * ▼ */
    if (ch == ' ') {
      if (spc_skip == false) {
        y++;
        x = st_x;
        spc_skip = true;
      }
      continue;
    }
    spc_skip = false;
    /* ▼ Eсли попадается знак тетромино */
    if (ch == L'■') { // ■
      /* ▼ Если блок занят, то создать фигуру не можем  */
      if (mode == 0 && (field[y][x] == RedIMvg || field[y][x] == GreenLMvg ||
                        field[y][x] == YellowZMvg || field[y][x] == BlueJMvg ||
                        field[y][x] == MagentaOMvg || field[y][x] == CyanSMvg ||
                        field[y][x] == WhiteTMvg)) {
        blks++;
      } else if (mode == 1 &&
                 (field[y][x] == RedIStc || field[y][x] == GreenLStc ||
                  field[y][x] == YellowZStc || field[y][x] == BlueJStc ||
                  field[y][x] == MagentaOStc || field[y][x] == CyanSStc ||
                  field[y][x] == WhiteTStc)) {
        blks++;
      }
    }
    /* Координату x прибавляем всегда, если там будет знак тетромино понятно,
      потому что эту точку мы уже отметили, однако если там будет "*", нам всё
      равно нужно сдвигать координату, потому что в моей системе знак точки
      означает отсутствие знака тетромино ▼ */
    x++;
  }
  return blks;
}

int tmino_detect(int **field) {
  int mvg = 0;
  for (int i = 0; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      if (mvg_px_dtrm(field[i][j])) {
        mvg++;
      }
    }
  }
  return mvg;
}
