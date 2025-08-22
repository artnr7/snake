#include "../../brick_game/tetris/include/init.h"

#include "test.h"

// START_TEST() {} END_TEST

START_TEST(get_g_info_1) {
  GameInfo_t *a = get_g_info();
  GameInfo_t *b = get_g_info();

  ck_assert_ptr_eq(a, b);
}
END_TEST

START_TEST(fld_nxt_frm_1) {
  int **a = fld_nxt_frm(0);
  int **b = fld_nxt_frm(0);

  ck_assert_ptr_eq(a, b);
  ck_assert_ptr_nonnull(a);
  ck_assert_ptr_nonnull(b);
}
END_TEST

START_TEST(g_info_init_1) {
  GameInfo_t *tg_info = get_g_info();
  GameInfo_t test_tg_info;
  g_info_init(tg_info);
  g_info_init(&test_tg_info);

  ck_assert_int_eq(tg_info->high_score, test_tg_info.high_score);
  ck_assert_int_eq(tg_info->pause, 0);
  ck_assert_int_eq(tg_info->level, 0);
  ck_assert_int_eq(tg_info->score, 0);
  ck_assert_int_eq(tg_info->speed, 0);

  g_info_and_nxt_frm_free(tg_info);
  free(test_tg_info.field);
  free(test_tg_info.next);
}
END_TEST

START_TEST(fld_malloc_and_fill_1) {
  GameInfo_t *tg_info = get_g_info();

  fld_malloc_and_fill(&(tg_info->field), FIELD_H, FIELD_W);
  fld_malloc_and_fill(&(tg_info->next), NEXT_TMINO_H, NEXT_TMINO_W);

  ck_assert_ptr_nonnull(tg_info->field);
  ck_assert_ptr_nonnull(tg_info->next);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(malloc_check_1) {
  GameInfo_t *tg_info = get_g_info();
  fld_malloc_and_fill(&(tg_info->field), FIELD_H, FIELD_W);
  fld_malloc_and_fill(&(tg_info->next), NEXT_TMINO_H, NEXT_TMINO_W);
  free(tg_info->next);
  tg_info->next = NULL;

  malloc_check(tg_info);

  int **nxt_frm = fld_nxt_frm(0);

  ck_assert_ptr_null(nxt_frm);
  ck_assert_ptr_null(tg_info->field);
  ck_assert_ptr_null(tg_info->next);
}
END_TEST

START_TEST(tg_info_free_1) {
  GameInfo_t *tg_info = get_g_info();

  fld_malloc_and_fill(&(tg_info->field), FIELD_H, FIELD_W);
  fld_malloc_and_fill(&(tg_info->next), NEXT_TMINO_H, NEXT_TMINO_W);

  g_info_and_nxt_frm_free(tg_info);

  ck_assert_ptr_null(tg_info->field);
  ck_assert_ptr_null(tg_info->next);
}
END_TEST

START_TEST(tminos_init_1) {
  Tetromino_t *tmino = tminos_init();
  ck_assert_int_eq(wcscmp(tmino[0].shape, L"■■■■"), 0);

  ck_assert_int_eq(tmino[0].px_code, RedIMvg);

  ck_assert_int_eq(wcscmp(tmino[1].shape,

                          L"**■\
             ■■■"),
                   0);
  ck_assert_int_eq(tmino[1].px_code, GreenLMvg);

  ck_assert_int_eq(wcscmp(tmino[2].shape,

                          L"■■*\
             *■■"),
                   0);
  ck_assert_int_eq(tmino[2].px_code, YellowZMvg);

  ck_assert_int_eq(wcscmp(tmino[3].shape,

                          L"■**\
             ■■■"),
                   0);
  ck_assert_int_eq(tmino[3].px_code, BlueJMvg);

  ck_assert_int_eq(wcscmp(tmino[4].shape,

                          L"■■\
             ■■"),
                   0);
  ck_assert_int_eq(tmino[4].px_code, MagentaOMvg);

  ck_assert_int_eq(wcscmp(tmino[5].shape,

                          L"*■■\
             ■■*"),
                   0);
  ck_assert_int_eq(tmino[5].px_code, CyanSMvg);

  ck_assert_int_eq(wcscmp(tmino[6].shape,

                          L"*■*\
             ■■■"),
                   0);
  ck_assert_int_eq(tmino[6].px_code, WhiteTMvg);
}
END_TEST

Suite *init_test_suite(void) {
  Suite *s;
  TCase *tc_init;
  s = suite_create("\n init_test_suite");
  tc_init = tcase_create("\n init_test_suite");
  tcase_add_test(tc_init, get_g_info_1);
  tcase_add_test(tc_init, fld_nxt_frm_1);
  tcase_add_test(tc_init, g_info_init_1);
  tcase_add_test(tc_init, fld_malloc_and_fill_1);
  tcase_add_test(tc_init, malloc_check_1);
  tcase_add_test(tc_init, tg_info_free_1);
  tcase_add_test(tc_init, tminos_init_1);

  suite_add_tcase(s, tc_init);
  return s;
}