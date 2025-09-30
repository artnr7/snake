#include "../../brick_game/tetris/include/moving/left_right_move.h"

#include "../../brick_game/tetris/include/tmino_create.h"
#include "test.h"
#include "test_utils.h"

START_TEST(lr_mv_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  UserAction_t action = Left;

  lr_mv(tg_info, action);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X - 1, 0),
      4);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(lr_mv_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  UserAction_t action = Right;

  lr_mv(tg_info, action);

  ck_assert_int_eq(
      move_detect(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X + 1, 0),
      4);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(lr_shift_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  UserAction_t action = Left;
  CanTetrominoMove_t can_tmino_mv = ToLeft;
  bool mvd = false;

  int **nxt_frm = fld_nxt_frm(0);

  lr_shift(*tg_info, nxt_frm, action, can_tmino_mv, &mvd);

  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X - 1, 0), 4);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(lr_shift_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  UserAction_t action = Right;
  CanTetrominoMove_t can_tmino_mv = ToRight;
  bool mvd = false;

  int **nxt_frm = fld_nxt_frm(0);

  lr_shift(*tg_info, nxt_frm, action, can_tmino_mv, &mvd);

  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X + 1, 0), 4);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(lr_shift_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  UserAction_t action = Right;
  CanTetrominoMove_t can_tmino_mv = NoWay;
  bool mvd = false;

  int **nxt_frm = fld_nxt_frm(0);

  lr_shift(*tg_info, nxt_frm, action, can_tmino_mv, &mvd);

  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X, 0), 4);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(lr_shift_4) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  tg_info->pause = 1;

  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  UserAction_t action = Left;
  CanTetrominoMove_t can_tmino_mv = ToLeft;
  bool mvd = false;

  int **nxt_frm = fld_nxt_frm(0);

  lr_shift(*tg_info, nxt_frm, action, can_tmino_mv, &mvd);

  ck_assert_int_eq(
      move_detect(nxt_frm, *tmino, TMINO_START_Y, TMINO_START_X - 1, 0), 4);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

Suite *left_right_move_suite(void) {
  Suite *s;
  TCase *tc_left_right_move;
  s = suite_create("left_right_move_test_suite");
  tc_left_right_move = tcase_create("left_right_move_test_suite");

  tcase_add_test(tc_left_right_move, lr_mv_1);
  tcase_add_test(tc_left_right_move, lr_mv_2);

  tcase_add_test(tc_left_right_move, lr_shift_1);
  tcase_add_test(tc_left_right_move, lr_shift_2);
  tcase_add_test(tc_left_right_move, lr_shift_3);
  tcase_add_test(tc_left_right_move, lr_shift_4);

  suite_add_tcase(s, tc_left_right_move);
  return s;
}