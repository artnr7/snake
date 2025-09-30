#include "../../brick_game/tetris/backend.h"

#include "../../brick_game/tetris/include/tmino_create.h"
#include "test.h"

START_TEST(userInput_1) {
  UserAction_t action = Start;
  bool hold = false;
  userInput(action, hold);

  GameInfo_t *tg_info_test = get_g_info();
  ck_assert_ptr_nonnull(tg_info_test);
}
END_TEST

START_TEST(updateCurrentState_1) {
  UserAction_t action = Start;
  bool hold = false;
  userInput(action, hold);

  GameInfo_t tg_info_test = updateCurrentState();
  ck_assert_int_eq(tg_info_test.pause, Launched);
  ck_assert_int_eq(tg_info_test.level, 1);
  ck_assert_int_eq(tg_info_test.score, 0);
  ck_assert_int_eq(tg_info_test.speed, 500000);
  ck_assert_ptr_nonnull(tg_info_test.field);
  ck_assert_ptr_nonnull(tg_info_test.next);
}
END_TEST

Suite *backend_suite(void) {
  Suite *s;
  TCase *tc_backend;
  s = suite_create("backend_test_suite");
  tc_backend = tcase_create("backend_test_suite");

  tcase_add_test(tc_backend, userInput_1);
  tcase_add_test(tc_backend, updateCurrentState_1);

  suite_add_tcase(s, tc_backend);
  return s;
}