#ifndef TEST_H
#define TEST_H
#include <check.h>

Suite *init_test_suite(void);
Suite *timer_test_suite(void);
Suite *timer_tetromino_create_suite(void);
Suite *speed_and_levels_suite(void);
Suite *rows_hit_suite(void);
Suite *collision_suite(void);
Suite *backend_utils_suite(void);
Suite *tetromino_fall_suite(void);
Suite *rotate_suite(void);
Suite *moving_utils_suite(void);
Suite *left_right_move_suite(void);
Suite *backend_suite(void);

#endif
