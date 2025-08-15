#include "../include/menu.h"
#include <stdio.h>

/* В этом файле встречаются случайные числа для координат отрисовки в терминале
 * потому что я не хочу реализовывать функционал изменения их на основе
 * масштаба, и так уже toomuch */

/** @brief Прорисовка игры */
void rendering() {
  GameInfo_t g_info = updateCurrentState();
  if (g_info.pause == Terminated || g_info.pause == GameOvered) {
    return;
  }

  /* Масштаб игры, высчитывается относительно масштаба по горизонтали для более
  * равномерной картинки
  ▼ */
  int rend_scl_x = 4, // ◄ стандартно == 4, только rend_scl_x %2 == 0
      rend_scl_y = rend_scl_x / 2;

  /* ▼ Горизонтальный отступ от границ окна */
  int rend_shift_x = 10; // ◄ стандартно == 10
  /* ▼ Горизонтальный отступ от границ окна */
  int rend_shift_y = 7; // ◄ стандартно == 7

  logo_rend(rend_scl_x, rend_scl_y);
  info_rend(g_info, rend_scl_x, rend_scl_y, rend_shift_x, rend_shift_y);
  gamefield_and_next_frame_rend(g_info, rend_scl_x, rend_scl_y, rend_shift_x,
                                rend_shift_y);
  bord_rend(rend_scl_x, rend_scl_y, rend_shift_x, rend_shift_y);
}

/** @brief Прорисовка игрового поля и следующей фигуры */
void gamefield_and_next_frame_rend(GameInfo_t g_info, int rend_scl_x,
                                   int rend_scl_y, int rend_shift_x,
                                   int rend_shift_y) {
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      px_rend(i, j, rend_scl_x, rend_scl_y, rend_shift_x, rend_shift_y,
              determ_color(g_info.field[i][j]));
    }
  }

#ifdef TETRIS
  for (int i = 0; i < NEXT_TMINO_H; i++) {
    for (int j = 0; j < NEXT_TMINO_W; j++) {
      // printf("i = %d j = %d\n", i, j);
      px_rend(i, j, rend_scl_x, rend_scl_y, 2, 16,
              determ_color(g_info.next[i][j]));
    }
  }
#endif
}

/** @brief Прорисовка пикселя тетромино на игровом поле */
void px_rend(int gui_y, int gui_x, int rend_scl_x, int rend_scl_y,
             int rend_shift_x, int rend_shift_y, int px_clr) {
  attron(COLOR_PAIR(px_clr));
  char *ch = "█";
  if (px_clr == DefaultColor) {
    ch = " ";
  }

  for (int i = 0; i < rend_scl_y; i++) {
    /* ▼ Рисование в толщину по горизонтали и вертикали */
    for (int j = 0; j < rend_scl_x; j++) {
      mvprintw((gui_y + rend_shift_y + 1) * rend_scl_y + i,
               (gui_x + rend_shift_x + 1) * rend_scl_x + j, "%s", ch);
    } /* ▲ Смещение на один по осям за тем чтобы тетромино мог
       прорисовываться, не задевая обводку поля, которая считается первым что
       должно быть учтено при сдвиге */
  }
  attroff(COLOR_PAIR(px_clr));
}

void start_menu() {
  logo_rend();
  attron(COLOR_PAIR(2));
  mvprintw(14, 44, "PRESS S");
  attroff(COLOR_PAIR(2));
}

/** @brief Прорисовка обводки игрового поля */
void bord_rend(int rend_scl_x, int rend_scl_y, int rend_shift_x,
               int rend_shift_y) {
  /* ▼ Горизонтальная координата для верхней обводки */
  int top_y = rend_shift_y * rend_scl_y + (rend_scl_y - 1);
  /* ▲ -1 это толщина символа */

  /* ▼ Горизонтальная координата для нижней обводки */
  int bot_y = (FIELD_H + rend_shift_y + 1) * rend_scl_y;
  /* ▲ +1 это компенсация смещения прорисовки игрового поля */

  /* ▼ Вертикальная координата для левой обводки */
  int left_x = rend_shift_x * rend_scl_x + (rend_scl_x - 1);
  /* ▲ -1 это толщина символа */

  /* ▼ Вертикальная координата для правой обводки */
  int right_x = (FIELD_W + rend_shift_x + 1) * rend_scl_x;
  /* ▲ +1 это компенсация смещения прорисовки игрового поля */

  for (int i = 0; i < FIELD_H; i++) {
    lr_bord_rend(i, rend_scl_y, rend_shift_y, left_x, right_x);

    tb_bord_and_corner_rend(rend_scl_x, rend_shift_x, top_y, bot_y, left_x,
                            right_x);
  }
}

/** @brief Прорисовка левой и правой границ обводки игрового поля */
void lr_bord_rend(int i, int rend_scl_y, int rend_shift_y, int left_x,
                  int right_x) {
  /* ▼ +1 это компенсация смещения прорисовки игрового поля */
  int lr_bord_y = (i + rend_shift_y + 1) * rend_scl_y;

  /* ▼ Рисование в толщину по горизонтали */
  for (int j = 0; j < rend_scl_y; j++) {
    mvprintw(lr_bord_y + j, left_x, "║");
    mvprintw(lr_bord_y + j, right_x, "║");
  }
}

/** @brief Прорисовка верхней и нижней границ обводки игрового поля, а также его
 * углов */
void tb_bord_and_corner_rend(int rend_scl_x, int rend_shift_x, int top_y,
                             int bot_y, int left_x, int right_x) {
  for (int j = 0; j < FIELD_W; j++) {
    /* ▼ Рисование в толщину по вертикали */
    for (int k = 0; k < rend_scl_x; k++) {
      /* ▼ +1 это компенсация смещения прорисовки игрового поля */
      int tb_bord_x = (j + rend_shift_x + 1) * rend_scl_x + k;

      /* ▼ Верхняя часть обводки */
      mvprintw(top_y, tb_bord_x, "═");
      /* ▼ Нижняя часть обводки */
      mvprintw(bot_y, tb_bord_x, "═");
    }

    /* ▼ Уголки */
    mvprintw(top_y, left_x, "╔");
    mvprintw(top_y, right_x, "╗");
    mvprintw(bot_y, left_x, "╚");
    mvprintw(bot_y, right_x, "╝");

    /* ▼ Сдвигаем надоедливый конец строки */
    mvprintw(bot_y, right_x + rend_scl_x + 5, " ");
  }
}

/** @brief Прорисовка  информационной части Тетриса
 * @details Управление, счёт
 */
void info_rend(GameInfo_t g_info, int rend_scl_x, int rend_scl_y,
               int rend_shift_x, int rend_shift_y) {
  int info_y = rend_shift_y * rend_scl_y - 1;
  int info_x = rend_shift_x * rend_scl_x / 2;
  /* Здесь просто случайные числа потому что я устал делать масштаб и просто
   * подогнал все положения под один масштаб
   ▼ */
  info_action_rend(info_y);
  player_info_rend(g_info, info_y, info_x);
}

/** @brief Прорисовка управления в информационной части */
void info_action_rend(int info_y) {
  wchar_t *start_exit = L"\n\
      █  PRESS S   █      PRESS Q    █\n\
 █▀▀▀▐█▌▄▀▀██ █▀▀█▐█▌    █▀▀█ █ █ ▀ ▐█▌\n\
 █▄▄▄ █ █  ██ █    █     █▄▄█  █  █  █\n\
 ▄▄▄█ █ ▀██ █ █    █     █▄▄▄ █ █ █  █";

  wchar_t *pause = L"\n\
\t█▀█ ▄▀▀██ █ █ █▀▀▀ █▀▀█\n\
\t█▄█ █  ██ █ █ █▄▄▄ █▄▄█\n\
\t█   ▀██ █ █▄█ ▄▄▄█ █▄▄▄\n\
\t       PRESS T ";

  mvprintw(info_y, 0, "%ls", start_exit);
  mvprintw(info_y + 5, 0, "%ls", pause);
}

/** @brief Прорисовка счёта в информационной части */
void player_info_rend(GameInfo_t g_info, int info_y, int info_x) {
  wchar_t *next = L"\n\
\t                █\n\
\t  ▄▄▄▄ █▀▀█ █ █▐█▌\n\
\t  █  █ █▄▄█  █  █\n\
\t  █  █ █▄▄▄ █ █ █";

  wchar_t *score = L"\n\
\t█▀▀▀ █▀▀▀ █▀▀█ █▀▀█ █▀▀█\n\
\t█▄▄▄ █    █  █ █    █▄▄█\n\
\t▄▄▄█ █▄▄▄ █▄▄█ █    █▄▄▄";

  wchar_t *level = L"\n\
\t    █               █\n\
\t    █ █▀▀█ █ █ █▀▀█ █\n\
\t    █ █▄▄█ █▄█ █▄▄█ █\n\
\t    █ █▄▄▄ ▀█▀ █▄▄▄ █";

  wchar_t *highscore = L"\n\
 ▄                                       \n\
 █▄▄▄ ▀ █▀▀█ █▄▄▄ █▀▀▀ █▀▀▀ █▀▀█ █▀▀█ █▀▀█\n\
 █  █ █ █▄▄█ █  █ █▄▄▄ █    █  █ █    █▄▄█\n\
 █  █ █ ▄▄▄█ █  █ ▄▄▄█ █▄▄▄ █▄▄█ █    █▄▄▄";

  mvprintw(info_y + 15, 0, "%ls", next);
  mvprintw(info_y + 28, 0, "%ls", score);
  mvprintw(info_y + 32, 0, "%ls", level);
  mvprintw(info_y + 37, 0, "%ls", highscore);
  mvprintw(info_y + 32, info_x, "%d", g_info.score);
  mvprintw(info_y + 37, info_x, "%d", g_info.level);
  mvprintw(info_y + 42, info_x, "%d", g_info.high_score);
}
/** @brief Прорисовка названия игры
 * @todo Сделать чтение из файла по-хорошему, но не хочу тратить время
 */
void logo_rend() {
  wchar_t *logo = L"\n\
████████████████ ███████████████ ████████████████   ██████████████ ████████    █████████████\n\
████████████████ ███████████████ ████████████████  ███████████████ ████████  ███████████████\n\
███   ████   ███  ████       ███ ███   ████   ███ ██████    █████  ████████ ██████    █████ \n\
      ████        ████                 ████        █████    █████    ████   █████           \n\
      ████        ████                 ████         █████████████    ████    ███████        \n\
      ████        ███████████          ████         █████████████    ████     █████████     \n\
      ████        ███████████          ████        ██████████████    ████        ███████    \n\
      ████        ████                 ████       ██████    █████    ████    ██     ██████  \n\
      ████        ████                 ████       ██████    █████    ████   ████     ██████ \n\
     ▄████▄       ████       ███      ▄████▄      ██████    ██████ ████████ ███████  ██████ \n\
    ████████     ███████████████     ████████     ██████    ██████ ████████  █████████████  \n\
    ████████     ███████████████     ████████     ██████    ██████ ████████   ███████████";

  attron(COLOR_PAIR(4));
  mvprintw(0, 0, "%ls", logo);
  attroff(COLOR_PAIR(4));
}
