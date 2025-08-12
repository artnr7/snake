#ifndef __TETRIS_INIT__
#define __TETRIS_INIT__

#include <stdlib.h>

#include "conf.h"
#include "gamestate.h"
#include "speed_and_levels.h"

GameInfo_t *get_g_info();

int **fld_nxt_frm(int mode);

void g_info_init(GameInfo_t *g_info);

void fld_malloc_and_fill(int ***field, int H, int W);

bool malloc_check(GameInfo_t *g_info);

void g_info_and_nxt_frm_free(GameInfo_t *g_info);

Tetromino_t *tminos_init();

void go_end(GameInfo_t *g_info);
#endif