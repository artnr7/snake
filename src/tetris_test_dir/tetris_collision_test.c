#include "../brick_game/tetris/tetris_include/tetris_collision.h"

#include "../brick_game/tetris/tetris_include/tetris_moving/tetris_rotate.h"
#include "../brick_game/tetris/tetris_include/tetris_tetromino_create.h"
#include "test_utils.h"
#include "tetris_test.h"

// START_TEST() {} END_TEST

START_TEST(is_blk_insd_1) {
  for (int k = -3; k < FLD_H + 3; k++) {
    for (int l = -3; l < FLD_W + 3; l++) {
      if ((k >= 0 && k < FLD_H) && (l >= 0 && l < FLD_W)) {
        ck_assert_int_eq(is_blk_insd(k, l), true);
      } else {
        ck_assert_int_eq(is_blk_insd(k, l), false);
      }
    }
  }
}
END_TEST

/* Поворот в пустом поле */
START_TEST(can_tmino_rot_fn_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t *tmino = tmino_stc_obj();
  int tmino_pos = 1;

  fld_tmino_create(tg_info, tmino, &tmino_pos);

  int i = 0, j = 0, rot_mtx_h = 0, rot_mtx_w = 0;
  bool try_x_mv = false, can_tmino_rot = true;

  can_tmino_rot_fn(*tg_info, i, j, rot_mtx_h, rot_mtx_w, &try_x_mv,
                   &can_tmino_rot);

  ck_assert_int_eq(try_x_mv, false);
  ck_assert_int_eq(can_tmino_rot, true);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Поворот в заполненном поле */
START_TEST(can_tmino_rot_fn_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();

  chess_fill(tg_info->field);

  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);
  int pos = 0, i = 0, j = 0, rot_mtx_h = 3, rot_mtx_w = 3;
  bool try_x_mv = false, can_tmino_rot = true;

  fst_mvg_blk_find(*tg_info, &i, &j, &can_tmino_rot);

  rot_mtx(tg_info->field[i][j], &pos, &i, &j, &rot_mtx_h, &rot_mtx_w);

  can_tmino_rot_fn(*tg_info, i, j, rot_mtx_h, rot_mtx_w, &try_x_mv,
                   &can_tmino_rot);
  if (tmino->px_code == MagentaOMvg) {
    ck_assert_int_eq(try_x_mv, false);
    ck_assert_int_eq(can_tmino_rot, false);
  } else {
    ck_assert_int_eq(try_x_mv, true);
    ck_assert_int_eq(can_tmino_rot, true);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Поворот в заполненном поле, тетромино снизу */
START_TEST(can_tmino_rot_fn_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);

  Tetromino_t const *tmino = tmino_stc_obj();

  chess_fill(tg_info->field);

  tmino_parser(tg_info->field, *tmino, FLD_H - 2, TMINO_START_X, 0);
  int pos = 0, i = 0, j = 0, rot_mtx_h = 3, rot_mtx_w = 3;
  bool try_x_mv = false, can_tmino_rot = true;

  fst_mvg_blk_find(*tg_info, &i, &j, &can_tmino_rot);

  rot_mtx(tg_info->field[i][j], &pos, &i, &j, &rot_mtx_h, &rot_mtx_w);

  can_tmino_rot_fn(*tg_info, i, j, rot_mtx_h, rot_mtx_w, &try_x_mv,
                   &can_tmino_rot);

  if (tmino->px_code == WhiteTMvg) {
    ck_assert_int_eq(try_x_mv, true);
    ck_assert_int_eq(can_tmino_rot, true);
  } else if (tmino->px_code != MagentaOMvg) {
    ck_assert_int_eq(try_x_mv, false);
    ck_assert_int_eq(can_tmino_rot, false);
  }

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Пустое поле, тетромино сверху */
START_TEST(bot_coll_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  Tetromino_t const *tmino = tmino_stc_obj();

  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  ck_assert_int_eq(bot_coll(*tg_info), false);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Пустое поле, тетромино снизу */
START_TEST(bot_coll_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  Tetromino_t const *tmino = tmino_stc_obj();

  tmino_parser(tg_info->field, *tmino, FLD_H - 2, TMINO_START_X, 0);

  if (tmino->px_code == RedIMvg) {
    ck_assert_int_eq(bot_coll(*tg_info), false);
  } else {
    ck_assert_int_eq(bot_coll(*tg_info), true);
  }
  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Полное поле, тетромино снизу */
START_TEST(bot_coll_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  chess_fill(tg_info->field);
  Tetromino_t const *tmino = tmino_stc_obj();

  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  ck_assert_int_eq(bot_coll(*tg_info), true);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Пустое поле, тетромино сверху */
START_TEST(lr_brd_tmino_coll_1) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  WhoIsNearby_t who = {0};

  lr_brd_tmino_coll(tg_info, &who);

  ck_assert_int_eq(who.LBlock, false);
  ck_assert_int_eq(who.RBlock, false);
  ck_assert_int_eq(who.LBorder, false);
  ck_assert_int_eq(who.RBorder, false);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Полное поле, тетромино сверху */
START_TEST(lr_brd_tmino_coll_2) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  chess_fill(tg_info->field);
  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  WhoIsNearby_t who = {0};

  lr_brd_tmino_coll(tg_info, &who);

  ck_assert_int_eq(who.LBlock, true);
  ck_assert_int_eq(who.RBlock, true);
  ck_assert_int_eq(who.LBorder, false);
  ck_assert_int_eq(who.RBorder, false);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

/* Полное поле, тетромино сверху слева */
START_TEST(lr_brd_tmino_coll_3) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  tg_info_init(tg_info);
  chess_fill(tg_info->field);
  Tetromino_t const *tmino = tmino_stc_obj();
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X - 4, 0);

  WhoIsNearby_t who = {0};

  lr_brd_tmino_coll(tg_info, &who);

  if (tmino->px_code == 8 || tmino->px_code == 9 || tmino->px_code == 11 ||
      tmino->px_code == 12) {
    ck_assert_int_eq(who.LBlock, false);
  } else {
    ck_assert_int_eq(who.LBlock, true);
  }
  ck_assert_int_eq(who.RBlock, true);
  ck_assert_int_eq(who.LBorder, true);
  ck_assert_int_eq(who.RBorder, false);

  tg_info_and_nxt_frm_free(tg_info);
}
END_TEST

START_TEST(can_tmino_mv_fn_1) {
  WhoIsNearby_t who = {0};
  CanTetrominoMove_t can_tmino_mv = ToLeft;

  can_tmino_mv_fn(who, &can_tmino_mv);

  ck_assert_int_eq(can_tmino_mv, ToLeft);
}
END_TEST

START_TEST(can_tmino_mv_fn_2) {
  WhoIsNearby_t who = {1, 0, 0, 0};
  CanTetrominoMove_t can_tmino_mv = ToLeft;

  can_tmino_mv_fn(who, &can_tmino_mv);

  ck_assert_int_eq(can_tmino_mv, ToRight);
}
END_TEST

START_TEST(can_tmino_mv_fn_3) {
  WhoIsNearby_t who = {1, 0, 0, 1};

  CanTetrominoMove_t can_tmino_mv = ToLeft;

  can_tmino_mv_fn(who, &can_tmino_mv);

  ck_assert_int_eq(can_tmino_mv, NoWay);
}
END_TEST

Suite *tetris_collision_suite(void) {
  Suite *s;
  TCase *tc_collision;
  s = suite_create("tetris_collision_test_suite");
  tc_collision = tcase_create("tetris_collision_test_suite");

  tcase_add_test(tc_collision, is_blk_insd_1);

  tcase_add_test(tc_collision, can_tmino_rot_fn_1);
  tcase_add_test(tc_collision, can_tmino_rot_fn_2);
  tcase_add_test(tc_collision, can_tmino_rot_fn_3);

  tcase_add_test(tc_collision, bot_coll_1);
  tcase_add_test(tc_collision, bot_coll_2);
  tcase_add_test(tc_collision, bot_coll_3);

  tcase_add_test(tc_collision, lr_brd_tmino_coll_1);
  tcase_add_test(tc_collision, lr_brd_tmino_coll_2);
  tcase_add_test(tc_collision, lr_brd_tmino_coll_3);

  tcase_add_test(tc_collision, can_tmino_mv_fn_1);
  tcase_add_test(tc_collision, can_tmino_mv_fn_2);
  tcase_add_test(tc_collision, can_tmino_mv_fn_3);

  suite_add_tcase(s, tc_collision);
  return s;
}
