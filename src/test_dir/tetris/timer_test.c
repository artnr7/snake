#include "../../brick_game/tetris/include/timer.h"

#include <stdio.h>
#include <unistd.h>

#include "../../brick_game/tetris/include/init.h"
#include "test.h"

START_TEST(dly_get_1) {
  long dly = 0;

  dly_get(&dly);
  usleep(100000);  // ◄ 100 микросекунд
  dly_get(&dly);

  ck_assert_int_ge(dly, 100);
  ck_assert_int_le(dly, 110);
}
END_TEST

START_TEST(dly_reset_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  tg_info->speed = 500;
  long dly = 501;

  dly_reset(*tg_info, &dly);

  ck_assert_int_eq(dly, 0);
}
END_TEST

Suite *timer_test_suite(void) {
  Suite *s;
  TCase *tc_timer;
  s = suite_create("timer_test_suite");
  tc_timer = tcase_create("timer_test_suite");

  tcase_add_test(tc_timer, dly_get_1);
  tcase_add_test(tc_timer, dly_reset_1);

  suite_add_tcase(s, tc_timer);
  return s;
}