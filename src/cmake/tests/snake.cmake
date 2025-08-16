set(SNAKE_TEST snake_test)

file(GLOB SNAKE_TEST_FILES "test_dir/snake/*.cc" "test_dir/snake/*.hpp"
     ${SNAKE_BACK_SRC_INCLUDE})

add_executable(${SNAKE_TEST} ${SNAKE_TEST_FILES})

target_compile_options(${SNAKE_TEST} PRIVATE -DSNAKE -Wall -Werror -Wextra)

target_link_libraries(${SNAKE_TEST} PRIVATE GTest::GTest GTest::Main
                                            Threads::Threads)

add_test(NAME brick_game_${SNAKE_TEST} COMMAND ${SNAKE_TEST})

add_custom_target(
  run_${SNAKE_TEST}
  COMMAND $<TARGET_FILE:${SNAKE_TEST}>
  DEPENDS ${SNAKE_TEST})
