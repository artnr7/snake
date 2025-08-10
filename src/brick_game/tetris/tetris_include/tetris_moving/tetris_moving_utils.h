#ifndef __TETRIS_MOVING_UTILS__

#define __TETRIS_MOVING_UTILS__


#include "../tetris_data_types.h"
#include "../tetris_init.h"
#include <stdlib.h>

bool mvg_px_dtrm(PixelCode_t px);

bool stc_px_dtrm(PixelCode_t px);

void fld_cp(int **field, int **nxt_frm);

void fld_mvg_nthg_cp(int **field, int **nxt_frm);

#endif