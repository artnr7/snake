#ifndef __TETRIS_FRONTEND_UTILS__
#define __TETRIS_FRONTEND_UTILS__

#include <ncursesw/ncurses.h>

// #ifdef TETRIS
// #include "../../../brick_game/tetris/tetris_backend.h"
// #include "../../../brick_game/tetris/tetris_include/tetris_data_types.h"
// #elif SNAKE

// #endif
#include "tetris_menu.h"

void ncurses_init();

void tetris_fst_start(UserAction_t *action, bool *hold);

void tetris_main_loop(UserAction_t *action, bool *hold);

void keyboard_input(UserAction_t *action, bool *hold);

int clr_dtrm(int px);

#endif