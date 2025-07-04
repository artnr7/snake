#include "tetris_frontend.h"

void tetris_gui() {
  ncurses_init();

  UserAction_t action = Pause;
  static bool hold = false;

  tetris_fst_start(&action, &hold);
  tetris_main_loop(&action, &hold);

  endwin();
}

/** @mainpage
 * Моя интерпретация культовой игры ТЕТРИС
 */