set(TETRIS_TEST tetris_test)

file(GLOB TETRIS_TEST_FILES "test_dir/tetris/*.c" "test_dir/tetris/*.h")

add_executable(${TETRIS_TEST} ${TETRIS_TEST_FILES})

target_compile_options(${TETRIS_TEST} PRIVATE -Wall -Werror -Wextra)

target_link_libraries(${TETRIS_TEST} PRIVATE check subunit pthread ncursesw
                                             tetris_back_lib)

add_test(NAME brick_game_${TETRIS_TEST} COMMAND ${TETRIS_TEST})

add_custom_target(
  run_${TETRIS_TEST}
  COMMAND $<TARGET_FILE:${TETRIS_TEST}>
  DEPENDS ${TETRIS_TEST})
