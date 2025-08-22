#include "../../brick_game/tetris/include/backend_utils.h"

#include "../../brick_game/tetris/include/tmino_create.h"
#include "test.h"
#include "test_utils.h"

// START_TEST(act_fncs_1) {
//   GameInfo_t *g_info = get_g_info();
//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 0;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);

//   ck_assert_int_eq(g_info->pause, 2);
//   ck_assert_int_eq(g_info->level, 0);
//   ck_assert_int_eq(g_info->score, 0);
//   ck_assert_int_eq(g_info->speed, 0);

//   g_info_and_nxt_frm_free(g_info);
// }
// END_TEST

// START_TEST(act_fncs_2) {
//   GameInfo_t *g_info = get_g_info();

//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 0;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);
//   g_info->pause = 1;
//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);

//   ck_assert_int_eq(g_info->pause, 2);
//   ck_assert_int_eq(g_info->level, 0);
//   ck_assert_int_eq(g_info->score, 0);
//   ck_assert_int_eq(g_info->speed, 0);

//   g_info_and_nxt_frm_free(g_info);
// }
// END_TEST

// START_TEST(act_fncs_3) {
//   GameInfo_t *g_info = get_g_info();

//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 0;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);
//   act_fncs(g_info, Pause, dly, &tmino_fell, &tmino_pos);

//   ck_assert_int_eq(g_info->pause, 1);
//   ck_assert_int_eq(g_info->level, 0);
//   ck_assert_int_eq(g_info->score, 0);
//   ck_assert_int_eq(g_info->speed, 0);

//   g_info_and_nxt_frm_free(g_info);
// }
// END_TEST

// START_TEST(act_fncs_4) {
//   GameInfo_t *g_info = get_g_info();

//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 0;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);
//   act_fncs(g_info, Terminate, dly, &tmino_fell, &tmino_pos);

//   ck_assert_ptr_null(g_info->field);
//   ck_assert_ptr_null(g_info->next);
// }
// END_TEST

// START_TEST(act_fncs_5) {
//   GameInfo_t *g_info = get_g_info();

//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 0;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);
//   act_fncs(g_info, Left, dly, &tmino_fell, &tmino_pos);

//   ck_assert_int_eq(tmino_detect(g_info->field), 4);

//   g_info_and_nxt_frm_free(g_info);
// }
// END_TEST

// START_TEST(act_fncs_6) {
//   GameInfo_t *g_info = get_g_info();

//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 0;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);
//   act_fncs(g_info, Right, dly, &tmino_fell, &tmino_pos);

//   ck_assert_int_eq(tmino_detect(g_info->field), 4);

//   g_info_and_nxt_frm_free(g_info);
// }
// END_TEST

// START_TEST(act_fncs_7) {
//   GameInfo_t *g_info = get_g_info();

//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 1000;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);
//   act_fncs(g_info, -1, dly, &tmino_fell, &tmino_pos);

//   ck_assert_int_eq(tmino_detect(g_info->field), 4);

//   g_info_and_nxt_frm_free(g_info);
// }
// END_TEST

// START_TEST(act_fncs_8) {
//   GameInfo_t *g_info = get_g_info();

//   bool tmino_fell = false;
//   int tmino_pos = 0;
//   long int dly = 1000;

//   act_fncs(g_info, Start, dly, &tmino_fell, &tmino_pos);
//   act_fncs(g_info, Down, dly, &tmino_fell, &tmino_pos);

//   ck_assert_int_eq(tmino_detect(g_info->field), 0);

//   g_info_and_nxt_frm_free(g_info);
// }
// END_TEST

START_TEST(init_game_1) {
  GameInfo_t *g_info = get_g_info();

  int tmino_pos = 0;

  init_game(g_info, &tmino_pos);

  ck_assert_int_eq(g_info->pause, 2);
  ck_assert_int_eq(g_info->level, 0);
  ck_assert_int_eq(g_info->score, 0);
  ck_assert_int_eq(g_info->speed, 0);

  ck_assert_int_eq(tmino_detect(g_info->field), 4);

  g_info_and_nxt_frm_free(g_info);
}
END_TEST

START_TEST(init_game_2) {
  GameInfo_t *g_info = get_g_info();

  int tmino_pos = 0;

  init_game(g_info, &tmino_pos);
  g_info->pause = 1;
  init_game(g_info, &tmino_pos);

  ck_assert_int_eq(g_info->pause, 2);
  ck_assert_int_eq(g_info->level, 0);
  ck_assert_int_eq(g_info->score, 0);
  ck_assert_int_eq(g_info->speed, 0);

  ck_assert_int_eq(tmino_detect(g_info->field), 4);

  g_info_and_nxt_frm_free(g_info);
}
END_TEST

START_TEST(gamestep_1) {
  GameInfo_t *g_info = get_g_info();
  UserAction_t action = Pause;
  bool tmino_fell = false, hold = false;
  int tmino_pos = 0;
  long int dly = 0;

  init_game(g_info, &tmino_pos);
  g_info->score = 5000;
  gamestep(g_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
  ck_assert_int_eq(g_info->level, 9);
  g_info_and_nxt_frm_free(g_info);
}
END_TEST

START_TEST(gamestep_2) {
  GameInfo_t *g_info = get_g_info();
  UserAction_t action = Terminate;
  bool tmino_fell = false, hold = false;
  int tmino_pos = 0;
  long int dly = 0;

  init_game(g_info, &tmino_pos);
  g_info->score = 5000;
  gamestep(g_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
  ck_assert_int_eq(g_info->level, 0);
  g_info_and_nxt_frm_free(g_info);
}
END_TEST

START_TEST(gamestep_3) {
  GameInfo_t *g_info = get_g_info();
  UserAction_t action = Pause;
  bool tmino_fell = false, hold = false;
  int tmino_pos = 0;
  long int dly = 0;

  init_game(g_info, &tmino_pos);

  g_info->score = 5000;
  g_info->pause = 1;
  gamestep(g_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
  ck_assert_int_eq(g_info->level, 0);
  g_info_and_nxt_frm_free(g_info);
}
END_TEST

Suite *backend_utils_suite(void) {
  Suite *s;
  TCase *tc_backend_utils;
  s = suite_create("backend_utils_test_suite");
  tc_backend_utils = tcase_create("backend_utils_test_suite");

  // tcase_add_test(tc_backend_utils, act_fncs_1);
  // tcase_add_test(tc_backend_utils, act_fncs_2);
  // tcase_add_test(tc_backend_utils, act_fncs_3);
  // tcase_add_test(tc_backend_utils, act_fncs_4);
  // tcase_add_test(tc_backend_utils, act_fncs_5);
  // tcase_add_test(tc_backend_utils, act_fncs_6);
  // tcase_add_test(tc_backend_utils, act_fncs_7);
  // tcase_add_test(tc_backend_utils, act_fncs_8);

  tcase_add_test(tc_backend_utils, init_game_1);
  tcase_add_test(tc_backend_utils, init_game_2);

  tcase_add_test(tc_backend_utils, gamestep_1);
  tcase_add_test(tc_backend_utils, gamestep_2);
  tcase_add_test(tc_backend_utils, gamestep_3);

  suite_add_tcase(s, tc_backend_utils);
  return s;
}