#ifndef __TETRIS_SPEED_AND_LEVELS__
#define __TETRIS_SPEED_AND_LEVELS__

#include <stdlib.h>

#include "stdio.h"
#include "tetris_data_types.h"

#define LVL_QTY 10  // ◄ кол-во уровней в игре(не менять, не независ. величина)
#define SPD_MLT 50  // ◄ множитель скорости (оптимально 50)

void lvl_up(GameInfo_t *tg_info);

void high_scr_get(GameInfo_t *tg_info);

void high_scr_set(GameInfo_t *tg_info);

#endif