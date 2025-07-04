#ifndef __TETRIS_INIT__
#define __TETRIS_INIT__

#include <stdlib.h>

#include "tetris_data_types.h"
#include "tetris_speed_and_levels.h"

GameInfo_t *tg_info_stc_obj();

int **fld_nxt_frm(int mode);

void tg_info_init(GameInfo_t *tg_info);

void fld_malloc_and_fill(int ***field, int H, int W);

bool malloc_check(GameInfo_t *tg_info);

void tg_info_and_nxt_frm_free(GameInfo_t *tg_info);

Tetromino_t *tminos_init();

#endif