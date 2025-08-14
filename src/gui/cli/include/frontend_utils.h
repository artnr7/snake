#ifndef __TETRIS_FRONTEND_UTILS__
#define __TETRIS_FRONTEND_UTILS__

#include <ncursesw/ncurses.h>

#ifdef TETRIS
#include "../../../brick_game/tetris/backend.h"
#elif SNAKE
#include "../../../brick_game/snake/controller/controller_wrapper_for_c.h"
#include "../../../brick_game/tetris/include/defs.h"
#endif

#include "../../../brick_game/tetris/include/timer.h"
#include "menu.h"

void ncurses_init();

void start(UserAction_t *action, bool *hold);

void gameloop(UserAction_t *action, bool *hold);

void keyboard_input(UserAction_t *action, bool *hold);

int determ_color(int px);

#endif