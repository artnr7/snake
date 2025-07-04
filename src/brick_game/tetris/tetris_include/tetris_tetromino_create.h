#ifndef __TETRIS_TETROMINO_CREATE__
#define __TETRIS_TETROMINO_CREATE__

#include <time.h>

#include "tetris_data_types.h"
#include "tetris_init.h"
#include "tetris_moving/tetris_moving_utils.h"

Tetromino_t *tmino_stc_obj();

void get_tmino(Tetromino_t *tmino);

void fld_tmino_create(GameInfo_t *tg_info, Tetromino_t *tmino, int *tmino_pos);

void shall_create_tmino(GameInfo_t *tg_info, bool *tmino_fell, int *tmino_pos);

bool can_create_tmino_fn(GameInfo_t *tg_info, const Tetromino_t tmino);

bool tmino_parser(int **field, const Tetromino_t tmino, int st_y, int st_x,
                  int mode);

#endif