set(SNAKE_COVERAGE_TEST snake_coverage_test)

add_executable(${SNAKE_COVERAGE_TEST} ${SNAKE_TEST_FILES}
                                      ${SNAKE_BACK_SRC_INCLUDE})

target_link_libraries(${SNAKE_COVERAGE_TEST} PRIVATE GTest::GTest GTest::Main
                                                     Threads::Threads)

target_compile_options(
  ${SNAKE_COVERAGE_TEST}
  PRIVATE -DTEST
          -DSNAKE
          -Wall
          -Wextra
          -Werror
          -O0
          -g
          --coverage)

target_link_options(${SNAKE_COVERAGE_TEST} PRIVATE --coverage)

find_program(LCOV lcov)
find_program(GENHTML genhtml)

set(COVERAGE_DIR "${CMAKE_BINARY_DIR}/coverage")

add_custom_target(
  coverage
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target
          ${SNAKE_COVERAGE_TEST}
  COMMAND ${CMAKE_BINARY_DIR}/${SNAKE_COVERAGE_TEST}
  COMMAND
    lcov --capture --directory ${CMAKE_BINARY_DIR} --output-file coverage.info
    --ignore-errors mismatch,inconsistent --rc geninfo_unexecuted_blocks=1
    --quiet 2>/dev/null
  COMMAND
    lcov --remove coverage.info '/usr/*' '${CMAKE_SOURCE_DIR}/test_dir/*'
    --output-file coverage.filtered.info --ignore-errors inconsistent --quiet
    2>/dev/null
  COMMAND genhtml coverage.filtered.info --output-directory ${COVERAGE_DIR} -c
          ${CMAKE_SOURCE_DIR}/gcov/gcov.css --quiet
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  DEPENDS ${SNAKE_COVERAGE_TEST}
  COMMENT "Generating code coverage report")
