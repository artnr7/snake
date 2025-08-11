#ifndef __TETRIS_MENU__
#define __TETRIS_MENU__

#include "../../../brick_game/snake/controller/c_controller.h"
// #include "../../../brick_game/snake/data_types.h"
#include "../../../brick_game/tetris/tetris_include/tetris_data_types.h"
#include "tetris_frontend_utils.h"

void tetris_rendering(UserAction_t action);

void gamefield_and_nxt_frm_rend(GameInfo_t tg_info, int rend_scl_x,
                                int rend_scl_y, int rend_shift_x,
                                int rend_shift_y);

void px_rend(int gui_y, int gui_x, int rend_scl_x, int rend_scl_y,
             int rend_shift_x, int rend_shift_y, int px_clr);

void bord_rend(int render_scale_x, int render_scale_y, int render_shift_x,
               int render_shift_y);

void lr_bord_rend(int i, int rend_scl_y, int rend_shift_y, int left_j,
                  int right_j);

void tb_bord_and_corner_rend(int rend_scl_x, int rend_shift_x, int top_y,
                             int bot_y, int left_x, int right_x);

void info_rend(GameInfo_t tetris_gameinfo, int render_scale_x,
               int render_scale_y, int render_shift_x, int render_shift_y);

void info_action_rend(int info_y);

void player_info_rend(GameInfo_t tg_info, int info_y, int info_x);

void logo_rend();

void start_menu();

#endif