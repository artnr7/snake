#include "../brick_game/tetris/tetris_include/tetris_moving/tetris_rotate.h"

#include "../brick_game/tetris/tetris_include/tetris_init.h"
#include "../brick_game/tetris/tetris_include/tetris_tetromino_create.h"
#include "test_utils.h"
#include "tetris_test.h"

START_TEST(action_fn_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int pos = 0;
  bool tmino_fell = false;

  action_fn(tg_info, &pos, &tmino_fell);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(action_fn_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, FLD_H - 2, TMINO_START_X, 0);

  int pos = 0;
  bool tmino_fell = false;

  action_fn(tg_info, &pos, &tmino_fell);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(action_fn_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X + 2, 0);

  int pos = 0;
  bool tmino_fell = false;

  action_fn(tg_info, &pos, &tmino_fell);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(fst_mvg_blk_find_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int fst_blk_i = 0, fst_blk_j = 0;
  bool can_tmino_rot = true;

  fst_mvg_blk_find(*tg_info, &fst_blk_i, &fst_blk_j, &can_tmino_rot);

  if (tmino->px_code == 8) {
    ck_assert_int_eq(fst_blk_i, TMINO_START_Y);
    ck_assert_int_eq(fst_blk_j, TMINO_START_X);
    ck_assert_int_eq(can_tmino_rot, true);
  } else if (tmino->px_code == 9) {
    ck_assert_int_eq(fst_blk_i, TMINO_START_Y);
    ck_assert_int_eq(fst_blk_j, TMINO_START_X + 2);
    ck_assert_int_eq(can_tmino_rot, true);
  } else if (tmino->px_code == 10) {
    ck_assert_int_eq(fst_blk_i, TMINO_START_Y);
    ck_assert_int_eq(fst_blk_j, TMINO_START_X);
    ck_assert_int_eq(can_tmino_rot, true);
  } else if (tmino->px_code == 11) {
    ck_assert_int_eq(fst_blk_i, TMINO_START_Y);
    ck_assert_int_eq(fst_blk_j, TMINO_START_X);
    ck_assert_int_eq(can_tmino_rot, true);
  } else if (tmino->px_code == 12) {
    ck_assert_int_eq(fst_blk_i, TMINO_START_Y);
    ck_assert_int_eq(fst_blk_j, TMINO_START_X);
    ck_assert_int_eq(can_tmino_rot, false);
  } else if (tmino->px_code == 13) {
    ck_assert_int_eq(fst_blk_i, TMINO_START_Y);
    ck_assert_int_eq(fst_blk_j, TMINO_START_X + 1);
    ck_assert_int_eq(can_tmino_rot, true);
  } else if (tmino->px_code == 14) {
    ck_assert_int_eq(fst_blk_i, TMINO_START_Y);
    ck_assert_int_eq(fst_blk_j, TMINO_START_X + 1);
    ck_assert_int_eq(can_tmino_rot, true);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_way_decis_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int **nxt_frm = fld_nxt_frm(0);
  bool try_x_mv = false, can_tmino_rot = true, tmino_fell = false;
  int fst_blk_i = 0, fst_blk_j = 0, pos = 0;
  fst_mvg_blk_find(*tg_info, &fst_blk_i, &fst_blk_j, &can_tmino_rot);

  int rot_mtx_h = 3, rot_mtx_w = 3;
  rot_mtx(tg_info->field[fst_blk_i][fst_blk_j], &pos, &fst_blk_i, &fst_blk_j,
          &rot_mtx_h, &rot_mtx_w);

  tmino_way_decis(tg_info, nxt_frm, fst_blk_i, fst_blk_j, rot_mtx_h, rot_mtx_w,
                  try_x_mv, &pos, &tmino_fell, can_tmino_rot);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_way_decis_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  chess_fill(tg_info->field);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int **nxt_frm = fld_nxt_frm(0);
  bool try_x_mv = false, can_tmino_rot = true, tmino_fell = false;
  int fst_blk_i = 0, fst_blk_j = 0, pos = 0;
  fst_mvg_blk_find(*tg_info, &fst_blk_i, &fst_blk_j, &can_tmino_rot);

  int rot_mtx_h = 3, rot_mtx_w = 3;
  rot_mtx(tg_info->field[fst_blk_i][fst_blk_j], &pos, &fst_blk_i, &fst_blk_j,
          &rot_mtx_h, &rot_mtx_w);

  tmino_way_decis(tg_info, nxt_frm, fst_blk_i, fst_blk_j, rot_mtx_h, rot_mtx_w,
                  try_x_mv, &pos, &tmino_fell, can_tmino_rot);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(rot_mtx_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool can_tmino_rot = true;
  int fst_blk_i = 0, fst_blk_j = 0, pos = 0;
  int rot_mtx_h = 3, rot_mtx_w = 3;

  fst_mvg_blk_find(*tg_info, &fst_blk_i, &fst_blk_j, &can_tmino_rot);
  int i = fst_blk_i, j = fst_blk_j;
  int h = rot_mtx_h, w = rot_mtx_w;

  rot_mtx(tg_info->field[fst_blk_i][fst_blk_j], &pos, &fst_blk_i, &fst_blk_j,
          &rot_mtx_h, &rot_mtx_w);

  if (tmino->px_code == 8) {
    ck_assert_int_eq(fst_blk_i, i - 1);
    ck_assert_int_eq(fst_blk_j, j);
    ck_assert_int_eq(rot_mtx_h, h + fst_blk_i + 1);
    ck_assert_int_eq(rot_mtx_w, w + fst_blk_j + 1);

  } else if (tmino->px_code == 9) {
    ck_assert_int_eq(fst_blk_i, i);
    ck_assert_int_eq(fst_blk_j, j - 2);
    ck_assert_int_eq(rot_mtx_h, h + fst_blk_i);
    ck_assert_int_eq(rot_mtx_w, w + fst_blk_j);

  } else if (tmino->px_code == 10) {
    ck_assert_int_eq(fst_blk_i, i);
    ck_assert_int_eq(fst_blk_j, j);
    ck_assert_int_eq(rot_mtx_h, h + fst_blk_i);
    ck_assert_int_eq(rot_mtx_w, w + fst_blk_j);

  } else if (tmino->px_code == 11) {
    ck_assert_int_eq(fst_blk_i, i);
    ck_assert_int_eq(fst_blk_j, j);
    ck_assert_int_eq(rot_mtx_h, h + fst_blk_i);
    ck_assert_int_eq(rot_mtx_w, w + fst_blk_j);

  } else if (tmino->px_code == 12) {
    ck_assert_int_eq(fst_blk_i, i);
    ck_assert_int_eq(fst_blk_j, j);
    ck_assert_int_eq(rot_mtx_h, h + i);
    ck_assert_int_eq(rot_mtx_w, w + j);

  } else if (tmino->px_code == 13) {
    ck_assert_int_eq(fst_blk_i, i);
    ck_assert_int_eq(fst_blk_j, j - 1);
    ck_assert_int_eq(rot_mtx_h, h + fst_blk_i);
    ck_assert_int_eq(rot_mtx_w, w + fst_blk_j);

  } else if (tmino->px_code == 14) {
    ck_assert_int_eq(fst_blk_i, i - 1);
    ck_assert_int_eq(fst_blk_j, j - 1);
    ck_assert_int_eq(rot_mtx_h, h + fst_blk_i);
    ck_assert_int_eq(rot_mtx_w, w + fst_blk_j);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_shift_rot_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool can_tmino_rot = true, tmino_fell = false;
  int fst_blk_i = 0, fst_blk_j = 0, pos = 0;
  int rot_mtx_h = 3, rot_mtx_w = 3;

  fst_mvg_blk_find(*tg_info, &fst_blk_i, &fst_blk_j, &can_tmino_rot);

  rot_mtx(tg_info->field[fst_blk_i][fst_blk_j], &pos, &fst_blk_i, &fst_blk_j,
          &rot_mtx_h, &rot_mtx_w);

  tmino_shift_rot(tg_info, fst_blk_j, &pos, &tmino_fell, &can_tmino_rot);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}

START_TEST(red_i_rot_1) {
  int pos = 0, i = 2, j = 2;
  red_i_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 1);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(red_i_rot_2) {
  int pos = 1, i = 2, j = 2;
  red_i_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 0);
}
END_TEST

START_TEST(red_i_rot_3) {
  int pos = 2, i = 2, j = 2;
  red_i_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 0);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(green_l_rot_1) {
  int pos = 0, i = 2, j = 2;
  green_l_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 0);
}
END_TEST

START_TEST(green_l_rot_2) {
  int pos = 1, i = 2, j = 2;
  green_l_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 1);
}
END_TEST

START_TEST(green_l_rot_3) {
  int pos = 2, i = 2, j = 2;
  green_l_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 1);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(yellow_z_rot_1) {
  int pos = 0, i = 2, j = 2;
  yellow_z_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(yellow_z_rot_2) {
  int pos = 1, i = 2, j = 2;
  yellow_z_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 0);
}
END_TEST

START_TEST(yellow_z_rot_3) {
  int pos = 2, i = 2, j = 2;
  yellow_z_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 1);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(blue_j_rot_1) {
  int pos = 0, i = 2, j = 2;
  blue_j_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(blue_j_rot_2) {
  int pos = 1, i = 2, j = 2;
  blue_j_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 1);
}
END_TEST

START_TEST(blue_j_rot_3) {
  int pos = 2, i = 2, j = 2;
  blue_j_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 1);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(cyan_s_rot_1) {
  int pos = 0, i = 2, j = 2;
  cyan_s_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 1);
}
END_TEST

START_TEST(cyan_s_rot_2) {
  int pos = 1, i = 2, j = 2;
  cyan_s_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 1);
}
END_TEST

START_TEST(cyan_s_rot_3) {
  int pos = 2, i = 2, j = 2;
  cyan_s_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 1);
  ck_assert_int_eq(j, 1);
}
END_TEST

START_TEST(white_t_rot_1) {
  int pos = 0, i = 2, j = 2;
  white_t_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 1);
  ck_assert_int_eq(j, 1);
}
END_TEST

START_TEST(white_t_rot_2) {
  int pos = 1, i = 2, j = 2;
  white_t_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 2);
}
END_TEST

START_TEST(white_t_rot_3) {
  int pos = 2, i = 2, j = 2;
  white_t_rot(&pos, &i, &j);
  ck_assert_int_eq(i, 2);
  ck_assert_int_eq(j, 2);
}
END_TEST

Suite *tetris_rotate_suite(void) {
  Suite *s;
  TCase *tc_rotate;
  s = suite_create("tetris_rotate_test_suite");
  tc_rotate = tcase_create("tetris_rotate_test_suite");

  tcase_add_test(tc_rotate, action_fn_1);
  tcase_add_test(tc_rotate, action_fn_2);
  tcase_add_test(tc_rotate, action_fn_3);

  tcase_add_test(tc_rotate, fst_mvg_blk_find_1);

  tcase_add_test(tc_rotate, tmino_way_decis_1);
  tcase_add_test(tc_rotate, tmino_way_decis_2);

  tcase_add_test(tc_rotate, rot_mtx_1);

  tcase_add_test(tc_rotate, tmino_shift_rot_1);

  tcase_add_test(tc_rotate, red_i_rot_1);
  tcase_add_test(tc_rotate, red_i_rot_2);
  tcase_add_test(tc_rotate, red_i_rot_3);

  tcase_add_test(tc_rotate, green_l_rot_1);
  tcase_add_test(tc_rotate, green_l_rot_2);
  tcase_add_test(tc_rotate, green_l_rot_3);

  tcase_add_test(tc_rotate, yellow_z_rot_1);
  tcase_add_test(tc_rotate, yellow_z_rot_2);
  tcase_add_test(tc_rotate, yellow_z_rot_3);

  tcase_add_test(tc_rotate, blue_j_rot_1);
  tcase_add_test(tc_rotate, blue_j_rot_2);
  tcase_add_test(tc_rotate, blue_j_rot_3);

  tcase_add_test(tc_rotate, cyan_s_rot_1);
  tcase_add_test(tc_rotate, cyan_s_rot_2);
  tcase_add_test(tc_rotate, cyan_s_rot_3);

  tcase_add_test(tc_rotate, white_t_rot_1);
  tcase_add_test(tc_rotate, white_t_rot_2);
  tcase_add_test(tc_rotate, white_t_rot_3);

  suite_add_tcase(s, tc_rotate);
  return s;
}