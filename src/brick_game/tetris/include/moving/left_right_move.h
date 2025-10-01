#ifndef __TETRIS_LEFT_RIGHT_MOVE__
#define __TETRIS_LEFT_RIGHT_MOVE__

#include "../collision.h"
#include "moving_utils.h"

bool lr_mv(GameInfo_t *g_info, UserAction_t action);

void lr_shift(GameInfo_t g_info, int **nxt_frm, UserAction_t action,
              CanTetrominoMove_t can_tmino_mv, bool *mvd);

#endif