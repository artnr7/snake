#ifndef __MOVING_UTILS__
#define __MOVING_UTILS__

#include "../conf.h"
#include "../init.h"
#include <stdlib.h>

bool mvg_px_dtrm(PixelCode_t px);

bool stc_px_dtrm(PixelCode_t px);

void fld_cp(int **field, int **nxt_frm);

void fld_mvg_nthg_cp(int **field, int **nxt_frm);

#endif