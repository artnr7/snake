set(TETRIS_CLI tetris_cli)
set(PLAY_TETRIS_CLI play_${TETRIS_CLI})

include(cmake/srcs/cli_gui.cmake)
include(cmake/make_libs/tetris_back_lib.cmake)

set(TETRIS_CLI_SRC_INCLUDE play/cli.c ${CLI_GUI_SRC_INCLUDE})

add_executable(${TETRIS_CLI} ${TETRIS_CLI_SRC_INCLUDE})

target_compile_options(
  ${TETRIS_CLI}
  PRIVATE -DTETRIS
          -Wall
          -Werror
          -Wextra
          -std=c11
          -pedantic
          -lncursesw)

target_link_libraries(${TETRIS_CLI} PRIVATE Curses::Curses tetris_back_lib)

add_custom_target(
  ${PLAY_TETRIS_CLI}
  COMMAND $<TARGET_FILE:${TETRIS_CLI}>
  DEPENDS ${TETRIS_CLI})
