#ifndef __TETRIS_ROWS_HIT__
#define __TETRIS_ROWS_HIT__

#include "tetris_collision.h"
#include "tetris_data_types.h"
#include "tetris_moving/tetris_moving_utils.h"

void rows_hit(GameInfo_t *tg_info);

bool is_row_compl(GameInfo_t tg_info, int *full_row_i);

void tmino_collapse(GameInfo_t *tg_info, int full_row_i);

void scr_chg(GameInfo_t *tg_info, int ersd_rows_qty);

#endif