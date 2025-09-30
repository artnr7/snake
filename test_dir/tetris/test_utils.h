#ifndef __TEST_UTILS__
#define __TEST_UTILS__

#include "../../brick_game/tetris/include/conf.h"

void chess_fill(int **field);

void fill(int **field, int qty);

int move_detect(int **field, const Tetromino_t tmino, int st_y, int st_x,
                int mode);

int tmino_detect(int **field);

#endif