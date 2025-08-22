#include "../../brick_game/tetris/include/tmino_create.h"

#include "../../brick_game/tetris/include/init.h"
#include "test.h"
#include "test_utils.h"

// START_TEST() {} END_TEST

START_TEST(shall_create_tmino_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  bool tmino_fell = false;
  int tmino_pos = 1;

  shall_create_tmino(tg_info, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tmino_fell, false);
  ck_assert_int_eq(tmino_pos, 1);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(shall_create_tmino_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  bool tmino_fell = true;
  int tmino_pos = 1;

  shall_create_tmino(tg_info, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tmino_fell, false);
  ck_assert_int_eq(tmino_pos, 0);
  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(shall_create_tmino_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  bool tmino_fell = true;
  int tmino_pos = 1;

  chess_fill(tg_info->field);

  shall_create_tmino(tg_info, &tmino_fell, &tmino_pos);

  ck_assert_int_eq(tmino_fell, true);
  ck_assert_int_eq(tmino_pos, 1);

  ck_assert_ptr_null(tg_info->field);
  ck_assert_ptr_null(tg_info->next);
}
END_TEST

START_TEST(tmino_stc_obj_1) {
  Tetromino_t *a = tmino_stc_obj();
  Tetromino_t *b = tmino_stc_obj();

  ck_assert_ptr_eq(a, b);
  ck_assert_ptr_nonnull(a);
  ck_assert_ptr_nonnull(b);
}
END_TEST

/** @todo done*/
START_TEST(fld_tmino_create_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);

  Tetromino_t *tmino = tmino_stc_obj();
  int tmino_pos = 1;

  fld_tmino_create(tg_info, tmino, &tmino_pos);

  // test
  int mvg_f = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (mvg_px_dtrm(tg_info->field[i][j])) {
        mvg_f++;
      }
    }
  }
  int mvg_n = 0;
  for (int i = 0; i < NEXT_TMINO_H; i++) {
    for (int j = 0; j < NEXT_TMINO_W; j++) {
      if (mvg_px_dtrm(tg_info->next[i][j])) {
        mvg_n++;
      }
    }
  }
  ck_assert_int_eq(mvg_f, 4);  // ◄ 4 блока в тетромино всегда
  ck_assert_int_eq(mvg_n, 4);  // ◄ 4 блока в тетромино всегда
  ck_assert_int_eq(tmino_pos, 0);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(get_tmino_1) {
  Tetromino_t *tmino = tmino_stc_obj();
  get_tmino(tmino);
  if (tmino->px_code == 8) {
    ck_assert_int_eq(wcscmp(tmino->shape,

                            L"■■■■"),
                     0);
  }

  if (tmino->px_code == 9) {
    ck_assert_int_eq(wcscmp(tmino->shape,

                            L"**■\
             ■■■"),
                     0);
  }

  if (tmino->px_code == 10) {
    ck_assert_int_eq(wcscmp(tmino->shape,

                            L"■■*\
             *■■"),
                     0);
  }

  if (tmino->px_code == 11) {
    ck_assert_int_eq(wcscmp(tmino->shape,

                            L"■**\
             ■■■"),
                     0);
  }

  if (tmino->px_code == 12) {
    ck_assert_int_eq(wcscmp(tmino->shape,

                            L"■■\
             ■■"),
                     0);
  }

  if (tmino->px_code == 13) {
    ck_assert_int_eq(wcscmp(tmino->shape,

                            L"*■■\
             ■■*"),
                     0);
  }

  if (tmino->px_code == 14) {
    ck_assert_int_eq(wcscmp(tmino->shape,

                            L"*■*\
             ■■■"),
                     0);
  }

  ck_assert_int_ge(tmino->px_code, 8);
  ck_assert_int_le(tmino->px_code, 14);
}
END_TEST

START_TEST(can_create_tmino_fn_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  Tetromino_t const *tmino = tmino_stc_obj();

  ck_assert_int_eq(can_create_tmino_fn(tg_info, *tmino), true);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(can_create_tmino_fn_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  const Tetromino_t *tmino = tmino_stc_obj();
  chess_fill(tg_info->field);

  ck_assert_int_eq(can_create_tmino_fn(tg_info, *tmino), false);
}
END_TEST

START_TEST(tmino_parser_1) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  const Tetromino_t *tmino = tmino_stc_obj();

  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);
  int mvg_f = 0;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      if (mvg_px_dtrm(tg_info->field[i][j])) {
        mvg_f++;
      }
    }
  }
  ck_assert_int_eq(mvg_f, 4);  // ◄ 4 блока в тетромино всегда

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_parser_2) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  const Tetromino_t *tmino = tmino_stc_obj();

  ck_assert_int_eq(
      tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 1),
      true);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(tmino_parser_3) {
  GameInfo_t *tg_info = get_g_info();
  g_info_init(tg_info);
  const Tetromino_t *tmino = tmino_stc_obj();

  chess_fill(tg_info->field);
  ck_assert_int_eq(
      tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 1),
      false);

  g_info_and_nxt_frm_free(tg_info);
}
END_TEST

Suite *timer_tetromino_create_suite(void) {
  Suite *s;
  TCase *tc_tetromino_create;
  s = suite_create("tetromino_create_test_suite");
  tc_tetromino_create = tcase_create("tetromino_create_test_suite");

  tcase_add_test(tc_tetromino_create, shall_create_tmino_1);
  tcase_add_test(tc_tetromino_create, shall_create_tmino_2);
  tcase_add_test(tc_tetromino_create, shall_create_tmino_3);

  tcase_add_test(tc_tetromino_create, tmino_stc_obj_1);
  tcase_add_test(tc_tetromino_create, fld_tmino_create_1);
  tcase_add_test(tc_tetromino_create, get_tmino_1);

  tcase_add_test(tc_tetromino_create, can_create_tmino_fn_1);
  tcase_add_test(tc_tetromino_create, can_create_tmino_fn_2);

  tcase_add_test(tc_tetromino_create, tmino_parser_1);
  tcase_add_test(tc_tetromino_create, tmino_parser_2);
  tcase_add_test(tc_tetromino_create, tmino_parser_3);

  suite_add_tcase(s, tc_tetromino_create);
  return s;
}