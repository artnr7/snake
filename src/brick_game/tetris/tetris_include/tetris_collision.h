#ifndef __TETRIS_COLLISION__
#define __TETRIS_COLLISION__

#include "tetris_data_types.h"
#include "tetris_moving/tetris_moving_utils.h"

bool is_blk_insd(int i, int j);

void can_tmino_rot_fn(GameInfo_t tg_info, int i, int j, int rot_mtx_h,
                      int rot_mtx_w, bool *try_x_mv, bool *can_tmino_rot);

bool bot_coll(GameInfo_t tg_info);

void lr_brd_tmino_coll(const GameInfo_t *tg_info, WhoIsNearby_t *who_is_nearby);

void can_tmino_mv_fn(WhoIsNearby_t who_is_nearby,
                     CanTetrominoMove_t *can_tmino_mv);

#endif