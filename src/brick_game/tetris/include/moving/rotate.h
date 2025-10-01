#ifndef __TETRIS_ROTATE__
#define __TETRIS_ROTATE__

#include "../collision.h"
#include "left_right_move.h"
#include "moving_utils.h"

void tmino_spin(GameInfo_t *g_info, int *pos, bool *tmino_fell);

void fst_mvg_blk_find(GameInfo_t g_info, int *fst_blk_i, int *fst_blk_j,
                      bool *can_tmino_rot);

void tmino_way_decis(GameInfo_t *g_info, int **nxt_frm, int i, int j,
                     int rot_mtx_h, int rot_mtx_w, bool try_x_mv, int *pos,
                     bool *tmino_fell, bool can_tmino_rot);

void tmino_rot(GameInfo_t *g_info, int **nxt_frm, int i, int j, int rot_mtx_h,
               int rot_mtx_w);

void tmino_shift_rot(GameInfo_t *g_info, int j, int *pos, bool *tmino_fell,
                     bool *can_tmino_rot);

void rot_mtx(const int px, const int *pos, int *i, int *j, int *rot_mtx_h,
             int *rot_mtx_w);

void red_i_rot(const int *pos, int *i, int *j);

void green_l_rot(const int *pos, int *i, int *j);

void yellow_z_rot(const int *pos, int *i, int *j);

void blue_j_rot(const int *pos, int *i, int *j);

void cyan_s_rot(const int *pos, int *i, int *j);

void white_t_rot(const int *pos, int *i, int *j);
#endif