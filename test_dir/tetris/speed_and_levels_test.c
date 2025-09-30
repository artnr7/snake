#include "../../brick_game/tetris/include/speed_and_levels.h"

#include "../../brick_game/tetris/include/init.h"
#include "test.h"

// START_TEST() {} END_TEST

START_TEST(lvl_up_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  lvl_up(tg_info);

  ck_assert_int_eq(tg_info->level, 1);
  ck_assert_int_eq(tg_info->speed, 500000);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(lvl_up_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  tg_info->score = 5000;

  lvl_up(tg_info);

  ck_assert_int_eq(tg_info->level, 9);
  ck_assert_int_eq(tg_info->speed, 100000);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(lvl_up_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  tg_info->score = 50000;

  lvl_up(tg_info);

  ck_assert_int_eq(tg_info->level, 10);
  ck_assert_int_eq(tg_info->speed, 50000);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(high_scr_get_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  FILE *fp = fopen("../brick_game/tetris/data_base/highscore.txt", "w");
  if (fp) {
    char highscr_str[11];
    snprintf(highscr_str, 10, "%d", 10000);
    const char *highscr_str_ptr = highscr_str;
    fputs(highscr_str_ptr, fp);
    fclose(fp);
  }
  high_scr_get(tg_info);

  ck_assert_int_eq(tg_info->high_score, 10000);

  FILE *fp_1 = fopen("../brick_game/tetris/data_base/highscore.txt", "w");
  if (fp) {
    char highscr_str_1[11];
    snprintf(highscr_str_1, 10, "%d", 4444);
    const char *highscr_str_ptr_1 = highscr_str_1;
    fputs(highscr_str_ptr_1, fp_1);
    fclose(fp_1);
  }

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(high_scr_get_2) {
  FILE *fp = fopen("../brick_game/tetris/data_base/highscore.txt", "w");
  if (fp) {
    char highscr_str[11];
    snprintf(highscr_str, 10, "%d", 5555);
    const char *highscr_str_ptr = highscr_str;
    fputs(highscr_str_ptr, fp);
    fclose(fp);
  }

  remove("../brick_game/tetris/data_base/highscore.txt");

  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  high_scr_get(tg_info);

  ck_assert_int_eq(tg_info->high_score, 0);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(high_scr_set_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  tg_info->high_score = 4999;
  tg_info->score = 5000;

  high_scr_set(tg_info);

  high_scr_get(tg_info);

  ck_assert_int_eq(tg_info->high_score, 5000);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(high_scr_set_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  FILE *fp = fopen("../brick_game/tetris/data_base/highscore.txt", "w");
  if (fp) {
    char highscr_str[11];
    snprintf(highscr_str, 10, "%d", 6001);
    const char *highscr_str_ptr = highscr_str;
    fputs(highscr_str_ptr, fp);
    fclose(fp);
  }
  high_scr_get(tg_info);

  tg_info->score = 6000;
  high_scr_set(tg_info);

  high_scr_get(tg_info);

  ck_assert_int_eq(tg_info->high_score, 6001);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(high_scr_set_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  FILE *fp = fopen("../brick_game/tetris/data_base/highscore.txt", "w");
  if (fp) {
    char highscr_str[11];
    snprintf(highscr_str, 10, "%d", 322);
    const char *highscr_str_ptr = highscr_str;
    fputs(highscr_str_ptr, fp);
    fclose(fp);
  }
  high_scr_get(tg_info);

  remove("../brick_game/tetris/data_base/highscore.txt");

  tg_info->score = 500;

  high_scr_get(tg_info);
  high_scr_set(tg_info);

  ck_assert_int_eq(tg_info->high_score, 500);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

Suite *speed_and_levels_suite(void) {
  Suite *s;
  TCase *tc_speed_and_levels;
  s = suite_create("speed_and_levels_test_suite");
  tc_speed_and_levels = tcase_create("speed_and_levels_test_suite");

  tcase_add_test(tc_speed_and_levels, lvl_up_1);
  tcase_add_test(tc_speed_and_levels, lvl_up_2);
  tcase_add_test(tc_speed_and_levels, lvl_up_3);

  tcase_add_test(tc_speed_and_levels, high_scr_get_1);
  tcase_add_test(tc_speed_and_levels, high_scr_get_2);

  tcase_add_test(tc_speed_and_levels, high_scr_set_1);
  tcase_add_test(tc_speed_and_levels, high_scr_set_2);
  tcase_add_test(tc_speed_and_levels, high_scr_set_3);

  suite_add_tcase(s, tc_speed_and_levels);
  return s;
}