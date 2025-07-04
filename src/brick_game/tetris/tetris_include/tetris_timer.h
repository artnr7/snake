#ifndef __TETRIS_TIMER__
#define __TETRIS_TIMER__

#include <stdlib.h>
#include <sys/time.h>

#include "../tetris_include/tetris_data_types.h"

#define MILLISEC_IN_SEC 1000
#define MICROSEC_IN_MILLISEC 1000

void dly_get(long int *dly);

void dly_reset(GameInfo_t tg_info, long int *dly);

#endif