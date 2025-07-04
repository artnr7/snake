#include "../brick_game/tetris/tetris_include/tetris_moving/tetris_moving_utils.h"

#include "../brick_game/tetris/tetris_include/tetris_init.h"
#include "../brick_game/tetris/tetris_include/tetris_moving/tetris_tetromino_fall.h"
#include "../brick_game/tetris/tetris_include/tetris_tetromino_create.h"
#include "tetris_test.h"

// START_TEST() {} END_TEST

START_TEST(mvg_px_dtrm_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  if (tmino->px_code == 8) {
    ck_assert_int_eq(mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 9) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X + 2]), true);
  } else if (tmino->px_code == 10) {
    ck_assert_int_eq(mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 11) {
    ck_assert_int_eq(mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 12) {
    ck_assert_int_eq(mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 13) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X + 1]), true);
  } else if (tmino->px_code == 14) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X + 1]), true);
  }
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(mvg_px_dtrm_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  if (tmino->px_code == 8) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y + 1][TMINO_START_X]), false);
  } else if (tmino->px_code == 9) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X + 1]), false);
  } else if (tmino->px_code == 10) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y + 1][TMINO_START_X]), false);
  } else if (tmino->px_code == 11) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X + 1]), false);
  } else if (tmino->px_code == 12) {
    ck_assert_int_eq(
        mvg_px_dtrm(tg_info->field[TMINO_START_Y + 2][TMINO_START_X]), false);
  } else if (tmino->px_code == 13) {
    ck_assert_int_eq(mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 14) {
    ck_assert_int_eq(mvg_px_dtrm(tg_info->field[TMINO_START_Y][TMINO_START_X]),
                     false);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(stc_px_dtrm_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool tmino_fell = false;

  action_down_fn(tg_info, &tmino_fell);

  if (tmino->px_code == 8) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 1][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 9) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 2][TMINO_START_X + 2]),
                     true);
  } else if (tmino->px_code == 10) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 2][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 11) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 2][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 12) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 2][TMINO_START_X]),
                     true);
  } else if (tmino->px_code == 13) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 2][TMINO_START_X + 1]),
                     true);
  } else if (tmino->px_code == 14) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 2][TMINO_START_X + 1]),
                     true);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(stc_px_dtrm_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool tmino_fell = false;

  tmino_fall(tg_info, &tmino_fell);

  if (tmino->px_code == 8) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 9) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X + 2]),
                     false);
  } else if (tmino->px_code == 10) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 11) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 12) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 13) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X + 1]),
                     false);
  } else if (tmino->px_code == 14) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X + 1]),
                     false);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(stc_px_dtrm_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool tmino_fell = false;

  tmino_fall(tg_info, &tmino_fell);

  if (tmino->px_code == 8) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 9) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X + 2]),
                     false);
  } else if (tmino->px_code == 10) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 11) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 12) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X]),
                     false);
  } else if (tmino->px_code == 13) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X + 1]),
                     false);
  } else if (tmino->px_code == 14) {
    ck_assert_int_eq(stc_px_dtrm(tg_info->field[FLD_H - 5][TMINO_START_X + 1]),
                     false);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(fld_cp_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int **nxt_frm = fld_nxt_frm(0);

  fld_cp(tg_info->field, nxt_frm);

  for (int i = 0; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      ck_assert_int_eq(tg_info->field[i][j], nxt_frm[i][j]);
    }
  }
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(fld_mvg_nthg_cp_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int **nxt_frm = fld_nxt_frm(0);

  fld_cp(tg_info->field, nxt_frm);

  for (int i = 0; i < FLD_H; i++) {
    for (int j = 0; j < FLD_W; j++) {
      ck_assert_int_eq(tg_info->field[i][j], nxt_frm[i][j]);
    }
  }
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

Suite *tetris_moving_utils_suite(void) {
  Suite *s;
  TCase *tc_moving_utils;
  s = suite_create("tetris_moving_utils_test_suite");
  tc_moving_utils = tcase_create("tetris_moving_utils_test_suite");

  tcase_add_test(tc_moving_utils, mvg_px_dtrm_1);
  tcase_add_test(tc_moving_utils, mvg_px_dtrm_2);

  tcase_add_test(tc_moving_utils, stc_px_dtrm_1);
  tcase_add_test(tc_moving_utils, stc_px_dtrm_2);
  tcase_add_test(tc_moving_utils, stc_px_dtrm_3);

  tcase_add_test(tc_moving_utils, fld_cp_1);
  tcase_add_test(tc_moving_utils, fld_mvg_nthg_cp_1);

  suite_add_tcase(s, tc_moving_utils);
  return s;
}