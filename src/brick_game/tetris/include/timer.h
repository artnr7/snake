#ifndef __TETRIS_TIMER__
#define __TETRIS_TIMER__

#include <stdlib.h>
#include <sys/time.h>

#include "../include/conf.h"

#define MILLISEC_IN_SEC 1000
#define MICROSEC_IN_MILLISEC 1000

void dly_get(long int *dly);

void dly_reset(GameInfo_t g_info, long int *dly);

#endif