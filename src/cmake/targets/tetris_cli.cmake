set(TETRIS_CLI tetris_cli)
set(PLAY_TETRIS_CLI play_${TETRIS_CLI})

include(cmake/srcs/tetris_back.cmake)
include(cmake/srcs/cli_gui.cmake)

set(TETRIS_CLI_SRC_INCLUDE
    tetris_cli.c ${TETRIS_BACK_SRC} ${TETRIS_BACK_INCLUDE} ${CLI_GUI_SRC}
    ${CLI_GUI_INCLUDE})

add_executable(${TETRIS_CLI} ${TETRIS_CLI_SRC_INCLUDE})

target_compile_options(${TETRIS_CLI} PRIVATE -DTETRIS -Wall -Werror -Wextra
                                             -lncursesw)

target_link_libraries(${TETRIS_CLI} PRIVATE Curses::Curses)

add_custom_target(
  ${PLAY_TETRIS_CLI}
  COMMAND $<TARGET_FILE:${TETRIS_CLI}>
  DEPENDS ${TETRIS_CLI})
