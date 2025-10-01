#include "../../brick_game/tetris/include/rows_hit.h"

#include "test.h"
#include "test_utils.h"

// START_TEST() {} END_TEST

START_TEST(rows_hit_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  fill(tg_info->field, 1);

  rows_hit(tg_info);

  int stc = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (stc_px_dtrm(tg_info->field[i][j])) {
        stc++;
      }
    }
  }
  ck_assert_int_eq(stc, 0);
  ck_assert_int_eq(tg_info->score, 100);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(rows_hit_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  fill(tg_info->field, 4);

  rows_hit(tg_info);

  int stc = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (stc_px_dtrm(tg_info->field[i][j])) {
        stc++;
      }
    }
  }
  ck_assert_int_eq(stc, 0);
  ck_assert_int_eq(tg_info->score, 1500);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(rows_hit_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  rows_hit(tg_info);

  int stc = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (stc_px_dtrm(tg_info->field[i][j])) {
        stc++;
      }
    }
  }
  ck_assert_int_eq(stc, 0);
  ck_assert_int_eq(tg_info->score, 0);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(is_row_compl_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  fill(tg_info->field, 4);
  int full_row_i = 0;

  ck_assert_int_eq(is_row_compl(*tg_info, &full_row_i), true);
  ck_assert_int_eq(full_row_i, 16);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(is_row_compl_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  fill(tg_info->field, 1);
  int full_row_i = 0;

  ck_assert_int_eq(is_row_compl(*tg_info, &full_row_i), true);
  ck_assert_int_eq(full_row_i, 19);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(is_row_compl_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  int full_row_i = 0;

  ck_assert_int_eq(is_row_compl(*tg_info, &full_row_i), false);
  ck_assert_int_eq(full_row_i, 0);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_collapse_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  fill(tg_info->field, 1);
  int full_row_i = 0;
  is_row_compl(*tg_info, &full_row_i);

  tmino_collapse(tg_info, full_row_i);

  int stc = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (stc_px_dtrm(tg_info->field[i][j])) {
        stc++;
      }
    }
  }
  ck_assert_int_eq(stc, 0);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_collapse_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  int full_row_i = 0;
  is_row_compl(*tg_info, &full_row_i);

  tmino_collapse(tg_info, full_row_i);

  int stc = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (stc_px_dtrm(tg_info->field[i][j])) {
        stc++;
      }
    }
  }
  ck_assert_int_eq(stc, 0);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_collapse_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  fill(tg_info->field, 4);
  int full_row_i = 0;
  is_row_compl(*tg_info, &full_row_i);

  tmino_collapse(tg_info, full_row_i);

  int stc = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (stc_px_dtrm(tg_info->field[i][j])) {
        stc++;
      }
    }
  }
  ck_assert_int_eq(stc, (4 - 1) * FIELD_W);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(scr_chg_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  int ersd_rows_qty = 4;

  scr_chg(tg_info, ersd_rows_qty);

  ck_assert_int_eq(tg_info->score, 1500);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(scr_chg_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  int ersd_rows_qty = 1;

  scr_chg(tg_info, ersd_rows_qty);

  ck_assert_int_eq(tg_info->score, 100);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(scr_chg_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  int ersd_rows_qty = 0;

  scr_chg(tg_info, ersd_rows_qty);

  ck_assert_int_eq(tg_info->score, 0);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(scr_chg_4) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  int ersd_rows_qty = 2;

  scr_chg(tg_info, ersd_rows_qty);

  ck_assert_int_eq(tg_info->score, 300);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(scr_chg_5) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  int ersd_rows_qty = 3;

  scr_chg(tg_info, ersd_rows_qty);

  ck_assert_int_eq(tg_info->score, 700);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

Suite *rows_hit_suite(void) {
  Suite *s;
  TCase *tc_rows_hit;
  s = suite_create("rows_hit_test_suite");
  tc_rows_hit = tcase_create("rows_hit_test_suite");

  tcase_add_test(tc_rows_hit, rows_hit_1);
  tcase_add_test(tc_rows_hit, rows_hit_2);
  tcase_add_test(tc_rows_hit, rows_hit_3);

  tcase_add_test(tc_rows_hit, is_row_compl_1);
  tcase_add_test(tc_rows_hit, is_row_compl_2);
  tcase_add_test(tc_rows_hit, is_row_compl_3);

  tcase_add_test(tc_rows_hit, tmino_collapse_1);
  tcase_add_test(tc_rows_hit, tmino_collapse_2);
  tcase_add_test(tc_rows_hit, tmino_collapse_3);

  tcase_add_test(tc_rows_hit, scr_chg_1);
  tcase_add_test(tc_rows_hit, scr_chg_2);
  tcase_add_test(tc_rows_hit, scr_chg_3);
  tcase_add_test(tc_rows_hit, scr_chg_4);
  tcase_add_test(tc_rows_hit, scr_chg_5);

  suite_add_tcase(s, tc_rows_hit);
  return s;
}