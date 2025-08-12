#ifndef __TETRIS_BACKEND_UTILS__
#define __TETRIS_BACKEND_UTILS__

#include "conf.h"
#include "gamestate.h"
#include "init.h"
#include "moving/moving.h"
#include "rows_hit.h"
#include "speed_and_levels.h"
#include "tmino_create.h"
#include "timer.h"

void init_game(GameInfo_t *g_info, int *tmino_pos);

void gamestep(GameInfo_t *g_info, const UserAction_t *action, long int *dly,
              bool *tmino_fell, int *tmino_pos, bool *hold);

#endif