#ifndef __TETRIS_SPEED_AND_LEVELS__
#define __TETRIS_SPEED_AND_LEVELS__

#include <stdlib.h>

#include "conf.h"
#include "stdio.h"

#define LVL_QTY 10  // ◄ кол-во уровней в игре(не менять, не независ. величина)
#define SPD_MLT 50000  // ◄ множитель скорости (оптимально 50000)

void lvl_up(GameInfo_t *g_info);

void high_scr_get(GameInfo_t *g_info);

void high_scr_set(GameInfo_t *g_info);

#endif