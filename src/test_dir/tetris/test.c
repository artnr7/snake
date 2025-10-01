#include "test.h"

#include <stdlib.h>

int main() {
  int success = 0;
  SRunner *runner;

  runner = srunner_create(NULL);

  srunner_add_suite(runner, init_test_suite());
  srunner_add_suite(runner, timer_test_suite());
  srunner_add_suite(runner, timer_tetromino_create_suite());
  srunner_add_suite(runner, speed_and_levels_suite());
  srunner_add_suite(runner, rows_hit_suite());
  srunner_add_suite(runner, collision_suite());
  srunner_add_suite(runner, backend_utils_suite());
  srunner_add_suite(runner, tetromino_fall_suite());
  srunner_add_suite(runner, rotate_suite());
  srunner_add_suite(runner, moving_utils_suite());
  srunner_add_suite(runner, left_right_move_suite());
  srunner_add_suite(runner, backend_suite());

  srunner_run_all(runner, CK_NORMAL);
  success = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (success == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}