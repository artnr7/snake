#include "frontend.h"

void frontend() {
  ncurses_init();

  UserAction_t action = Pause;
  bool hold = false;

  start(&action, &hold);
  gameloop(&action, &hold);

  endwin();
}

/** @mainpage
 * Моя интерпретация культовой игры ТЕТРИС
 */