#ifndef __TETRIS_ROWS_HIT__
#define __TETRIS_ROWS_HIT__

#include "collision.h"
#include "conf.h"
#include "moving/moving_utils.h"

void rows_hit(GameInfo_t *g_info);

bool is_row_compl(GameInfo_t g_info, int *full_row_i);

void tmino_collapse(GameInfo_t *g_info, int full_row_i);

void scr_chg(GameInfo_t *g_info, int ersd_rows_qty);

#endif