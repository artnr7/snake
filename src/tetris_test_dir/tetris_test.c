#include "tetris_test.h"

#include <stdlib.h>

int main() {
  int success = 0;
  SRunner *runner;

  runner = srunner_create(NULL);

  srunner_add_suite(runner, tetris_init_test_suite());
  srunner_add_suite(runner, tetris_timer_test_suite());
  srunner_add_suite(runner, tetris_timer_tetromino_create_suite());
  srunner_add_suite(runner, tetris_speed_and_levels_suite());
  srunner_add_suite(runner, tetris_rows_hit_suite());
  srunner_add_suite(runner, tetris_collision_suite());
  srunner_add_suite(runner, tetris_backend_utils_suite());
  srunner_add_suite(runner, tetris_tetromino_fall_suite());
  srunner_add_suite(runner, tetris_rotate_suite());
  srunner_add_suite(runner, tetris_moving_utils_suite());
  srunner_add_suite(runner, tetris_left_right_move_suite());
  srunner_add_suite(runner, tetris_backend_suite());

  srunner_run_all(runner, CK_NORMAL);
  success = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (success == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}