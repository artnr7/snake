#include "../brick_game/tetris/tetris_include/tetris_moving/tetris_tetromino_fall.h"

#include "../brick_game/tetris/tetris_include/tetris_tetromino_create.h"
#include "test_utils.h"
#include "tetris_test.h"

START_TEST(tmino_fall_with_dly_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  long int dly = 1000;
  bool tmino_fell = true;

  srand(1);
  rand_fall(tg_info, Left, dly, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y + 1, TMINO_START_X, 0),
      4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_fall_with_dly_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  long int dly = 0;
  bool tmino_fell = true;

  srand(1);
  rand_fall(tg_info, Left, dly, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(rand_fall_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  long int dly = 1000;
  bool tmino_fell = true;

  srand(1);
  rand_fall(tg_info, Left, dly, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y + 1, TMINO_START_X, 0),
      4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(rand_fall_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  long int dly = 1000;
  bool tmino_fell = true;

  srand(1);
  rand_fall(tg_info, Start, dly, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(rand_fall_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  long int dly = 0;
  bool tmino_fell = true;

  srand(1);
  rand_fall(tg_info, Left, dly, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_fall_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);
  bool tmino_fell = false;
  tmino_fall(tg_info, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y + 1, TMINO_START_X, 0),
      4);
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_fall_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, FLD_H - 2, TMINO_START_X, 0);

  bool tmino_fell = false;
  tmino_fall(tg_info, &tmino_fell);
  if (tmino->px_code == RedIMvg) {
    ck_assert_int_eq(
        move_detect(tg_info->field, *tmino, FLD_H - 1, TMINO_START_X, 0), 4);
  } else {
    ck_assert_int_eq(
        move_detect(tg_info->field, *tmino, FLD_H - 2, TMINO_START_X, 1), 4);
  }
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_fall_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  tg_info->pause = 1;
  bool tmino_fell = false;
  tmino_fall(tg_info, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_fall_4) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  chess_fill(tg_info->field);
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);
  bool tmino_fell = false;
  tmino_fall(tg_info, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 1), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(down_shift_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int **nxt_frm = fld_nxt_frm(0);
  fld_mvg_nthg_cp(tg_info->field, nxt_frm);

  bool tmino_fell = false;
  down_shift(tg_info->field, nxt_frm, tmino_fell);
  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y + 1, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(down_shift_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, FLD_H - 3, TMINO_START_X, 0);

  int **nxt_frm = fld_nxt_frm(0);
  fld_mvg_nthg_cp(tg_info->field, nxt_frm);

  bool tmino_fell = false;
  down_shift(tg_info->field, nxt_frm, tmino_fell);

  ck_assert_int_eq(move_detect(nxt_frm, *tmino, FLD_H - 2, TMINO_START_X, 0),
                   4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(down_shift_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  chess_fill(tg_info->field);
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  int **nxt_frm = fld_nxt_frm(0);
  fld_mvg_nthg_cp(tg_info->field, nxt_frm);

  bool tmino_fell = false;
  down_shift(tg_info->field, nxt_frm, tmino_fell);

  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y + 1, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_fixation_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  int **nxt_frm = fld_nxt_frm(0);
  fld_mvg_nthg_cp(tg_info->field, nxt_frm);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool tmino_fell = false;

  tmino_fixation(nxt_frm, tmino_fell);

  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_fixation_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  int **nxt_frm = fld_nxt_frm(0);
  fld_mvg_nthg_cp(tg_info->field, nxt_frm);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool tmino_fell = true;

  tmino_fixation(nxt_frm, tmino_fell);

  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X, 1), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(action_down_fn_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool tmino_fell = false;

  action_down_fn(tg_info, &tmino_fell);

  if (tmino->px_code == RedIMvg) {
    ck_assert_int_eq(
        move_detect(tg_info->field, *tmino, FLD_H - 1, TMINO_START_X, 1), 4);
  } else {
    ck_assert_int_eq(
        move_detect(tg_info->field, *tmino, FLD_H - 2, TMINO_START_X, 1), 4);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(action_down_fn_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  const Tetromino_t *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  bool tmino_fell = true;

  action_down_fn(tg_info, &tmino_fell);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

Suite *tetris_tetromino_fall_suite(void) {
  Suite *s;
  TCase *tc_tetromino_fall;
  s = suite_create("tetris_tetromino_fall_test_suite");
  tc_tetromino_fall = tcase_create("tetris_tetromino_fall_test_suite");

  tcase_add_test(tc_tetromino_fall, tmino_fall_with_dly_1);
  tcase_add_test(tc_tetromino_fall, tmino_fall_with_dly_2);

  tcase_add_test(tc_tetromino_fall, rand_fall_1);
  tcase_add_test(tc_tetromino_fall, rand_fall_2);
  tcase_add_test(tc_tetromino_fall, rand_fall_3);

  tcase_add_test(tc_tetromino_fall, tmino_fall_1);
  tcase_add_test(tc_tetromino_fall, tmino_fall_2);
  tcase_add_test(tc_tetromino_fall, tmino_fall_3);
  tcase_add_test(tc_tetromino_fall, tmino_fall_4);

  tcase_add_test(tc_tetromino_fall, down_shift_1);
  tcase_add_test(tc_tetromino_fall, down_shift_2);
  tcase_add_test(tc_tetromino_fall, down_shift_3);

  tcase_add_test(tc_tetromino_fall, tmino_fixation_1);
  tcase_add_test(tc_tetromino_fall, tmino_fixation_2);

  tcase_add_test(tc_tetromino_fall, action_down_fn_1);
  tcase_add_test(tc_tetromino_fall, action_down_fn_2);

  suite_add_tcase(s, tc_tetromino_fall);

  return s;
}