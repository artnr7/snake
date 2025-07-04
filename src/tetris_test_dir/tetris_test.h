#ifndef TEST_H
#define TEST_H
#include <check.h>

Suite *tetris_init_test_suite(void);
Suite *tetris_timer_test_suite(void);
Suite *tetris_timer_tetromino_create_suite(void);
Suite *tetris_speed_and_levels_suite(void);
Suite *tetris_rows_hit_suite(void);
Suite *tetris_collision_suite(void);
Suite *tetris_backend_utils_suite(void);
Suite *tetris_tetromino_fall_suite(void);
Suite *tetris_rotate_suite(void);
Suite *tetris_moving_utils_suite(void);
Suite *tetris_left_right_move_suite(void);
Suite *tetris_backend_suite(void);

#endif
