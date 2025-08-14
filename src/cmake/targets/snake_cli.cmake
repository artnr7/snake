set(SNAKE_CLI_ON TRUE)
set(SNAKE_CLI snake_cli)
set(PLAY_SNAKE_CLI play_${SNAKE_CLI})

include(cmake/srcs/cli_gui.cmake)
include(cmake/make_libs/snake_back_lib.cmake)

set(SNAKE_CLI_SRC_INCLUDE cli.c ${CLI_GUI_SRC_INCLUDE} ${SNAKE_BACK_SRC_INCLUDE})

add_executable(${SNAKE_CLI} ${SNAKE_CLI_SRC_INCLUDE})

target_compile_options(
  ${SNAKE_CLI}
  PRIVATE -DSNAKE
          -DCLI
          -Wall
          -Werror
          -Wextra
          # -std=c11
          -pedantic
          -lncursesw)

# target_link_libraries(${SNAKE_CLI} PRIVATE Curses::Curses snake_back_lib)
target_link_libraries(${SNAKE_CLI} PRIVATE Curses::Curses)
target_include_directories(${SNAKE_CLI} PRIVATE "brick_game/snake" "gui/cli"
                                                "brick_game/data_types")

add_custom_target(
  ${PLAY_SNAKE_CLI}
  COMMAND $<TARGET_FILE:${SNAKE_CLI}>
  DEPENDS ${SNAKE_CLI})

set(SNAKE_CLI_ON FALSE)
