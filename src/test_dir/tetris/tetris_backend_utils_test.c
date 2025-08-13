#include "../brick_game/tetris/tetris_include/tetris_backend_utils.h"

#include "../brick_game/tetris/tetris_include/tetris_tetromino_create.h"
#include "test_utils.h"
#include "tetris_test.h"

START_TEST(act_fncs_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tg_info->pause, 2);
  ck_assert_int_eq(tg_info->level, 0);
  ck_assert_int_eq(tg_info->score, 0);
  ck_assert_int_eq(tg_info->speed, 0);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(act_fncs_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  tg_info->pause = 1;
  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tg_info->pause, 2);
  ck_assert_int_eq(tg_info->level, 0);
  ck_assert_int_eq(tg_info->score, 0);
  ck_assert_int_eq(tg_info->speed, 0);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(act_fncs_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  act_fncs(tg_info, Pause, dly, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tg_info->pause, 1);
  ck_assert_int_eq(tg_info->level, 0);
  ck_assert_int_eq(tg_info->score, 0);
  ck_assert_int_eq(tg_info->speed, 0);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(act_fncs_4) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  act_fncs(tg_info, Terminate, dly, &tmino_fell, &tmino_pos);

  ck_assert_ptr_null(tg_info->field);
  ck_assert_ptr_null(tg_info->next);
}
END_TEST

START_TEST(act_fncs_5) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  act_fncs(tg_info, Left, dly, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(act_fncs_6) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  act_fncs(tg_info, Right, dly, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(act_fncs_7) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 1000;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  act_fncs(tg_info, -1, dly, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(act_fncs_8) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  bool tmino_fell = false;
  int tmino_pos = 0;
  long int dly = 1000;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  act_fncs(tg_info, Down, dly, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tmino_detect(tg_info->field), 0);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(start_fn_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  int tmino_pos = 0;

  start_fn(tg_info, &tmino_pos);

  ck_assert_int_eq(tg_info->pause, 2);
  ck_assert_int_eq(tg_info->level, 0);
  ck_assert_int_eq(tg_info->score, 0);
  ck_assert_int_eq(tg_info->speed, 0);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(start_fn_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();

  int tmino_pos = 0;

  start_fn(tg_info, &tmino_pos);
  tg_info->pause = 1;
  start_fn(tg_info, &tmino_pos);

  ck_assert_int_eq(tg_info->pause, 2);
  ck_assert_int_eq(tg_info->level, 0);
  ck_assert_int_eq(tg_info->score, 0);
  ck_assert_int_eq(tg_info->speed, 0);

  ck_assert_int_eq(tmino_detect(tg_info->field), 4);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(noact_fncs_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  UserAction_t action = Pause;
  bool tmino_fell = false, hold = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  tg_info->score = 5000;
  noact_fncs(tg_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
  ck_assert_int_eq(tg_info->level, 9);
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(noact_fncs_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  UserAction_t action = Terminate;
  bool tmino_fell = false, hold = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  tg_info->score = 5000;
  noact_fncs(tg_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
  ck_assert_int_eq(tg_info->level, 0);
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(noact_fncs_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  UserAction_t action = Pause;
  bool tmino_fell = false, hold = false;
  int tmino_pos = 0;
  long int dly = 0;

  act_fncs(tg_info, Start, dly, &tmino_fell, &tmino_pos);
  tg_info->score = 5000;
  tg_info->pause = 1;
  noact_fncs(tg_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
  ck_assert_int_eq(tg_info->level, 0);
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

Suite *tetris_backend_utils_suite(void) {
  Suite *s;
  TCase *tc_backend_utils;
  s = suite_create("tetris_backend_utils_test_suite");
  tc_backend_utils = tcase_create("tetris_backend_utils_test_suite");

  tcase_add_test(tc_backend_utils, act_fncs_1);
  tcase_add_test(tc_backend_utils, act_fncs_2);
  tcase_add_test(tc_backend_utils, act_fncs_3);
  tcase_add_test(tc_backend_utils, act_fncs_4);
  tcase_add_test(tc_backend_utils, act_fncs_5);
  tcase_add_test(tc_backend_utils, act_fncs_6);
  tcase_add_test(tc_backend_utils, act_fncs_7);
  tcase_add_test(tc_backend_utils, act_fncs_8);

  tcase_add_test(tc_backend_utils, start_fn_1);
  tcase_add_test(tc_backend_utils, start_fn_2);

  tcase_add_test(tc_backend_utils, noact_fncs_1);
  tcase_add_test(tc_backend_utils, noact_fncs_2);
  tcase_add_test(tc_backend_utils, noact_fncs_3);

  suite_add_tcase(s, tc_backend_utils);
  return s;
}