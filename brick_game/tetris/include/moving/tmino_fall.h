#ifndef __TETRIS_TETROMINO_FALL__
#define __TETRIS_TETROMINO_FALL__

#include "../collision.h"
#include "../gamestate.h"
#include "moving_utils.h"

void tmino_fall_with_dly(GameInfo_t *g_info, bool *tmino_fell, long int *dly);

void rand_fall(GameInfo_t *g_info, UserAction_t action, long int *dly,
               bool *tmino_fell);

void tmino_fall(GameInfo_t *g_info, bool *tmino_fell);

void down_shift(int **field, int **nxt_frm, bool tmino_fell);

void tmino_fixation(int **nxt_frm, bool tmino_fell);

void tmino_drop(GameInfo_t *g_info, bool *tmino_fell);

#endif