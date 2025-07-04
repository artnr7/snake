#ifndef __TETRIS_BACKEND_UTILS__
#define __TETRIS_BACKEND_UTILS__

#include "tetris_data_types.h"
#include "tetris_init.h"
#include "tetris_moving/tetris_moving.h"
#include "tetris_rows_hit.h"
#include "tetris_speed_and_levels.h"
#include "tetris_tetromino_create.h"
#include "tetris_timer.h"

void act_fncs(GameInfo_t *tg_info, UserAction_t action, long int dly,
              bool *tmino_fell, int *tmino_pos);

void start_fn(GameInfo_t *tg_info, int *tmino_pos);

void noact_fncs(GameInfo_t *tg_info, const UserAction_t *action, long int *dly,
                bool *tmino_fell, int *tmino_pos, bool *hold);

#endif