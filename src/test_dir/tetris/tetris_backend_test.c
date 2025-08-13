#include "../brick_game/tetris/tetris_backend.h"

#include "../brick_game/tetris/tetris_include/tetris_tetromino_create.h"
#include "tetris_test.h"

START_TEST(userInput_1) {
  UserAction_t action = Start;
  bool hold = false;
  userInput(action, hold);

  GameInfo_t *tg_info_test = tg_info_stc_obj();
  ck_assert_ptr_nonnull(tg_info_test);
}
END_TEST

START_TEST(updateCurrentState_1) {
  UserAction_t action = Start;
  bool hold = false;
  userInput(action, hold);

  GameInfo_t tg_info_test = updateCurrentState();
  ck_assert_int_eq(tg_info_test.pause, 2);
  ck_assert_int_eq(tg_info_test.level, 1);
  ck_assert_int_eq(tg_info_test.score, 0);
  ck_assert_int_eq(tg_info_test.speed, 500);
  ck_assert_ptr_nonnull(tg_info_test.field);
  ck_assert_ptr_nonnull(tg_info_test.next);
}
END_TEST

Suite *tetris_backend_suite(void) {
  Suite *s;
  TCase *tc_backend;
  s = suite_create("tetris_backend_test_suite");
  tc_backend = tcase_create("tetris_backend_test_suite");

  tcase_add_test(tc_backend, userInput_1);
  tcase_add_test(tc_backend, updateCurrentState_1);

  suite_add_tcase(s, tc_backend);
  return s;
}