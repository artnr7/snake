set(SNAKE_CLI_ON TRUE)
set(SNAKE_CLI snake_cli)
set(PLAY_SNAKE_CLI play_${SNAKE_CLI})

include(cmake/srcs/cli_gui.cmake)
include(cmake/make_libs/snake_back_lib.cmake)

set(SNAKE_CLI_SRC_INCLUDE play/cli.c ${CLI_GUI_SRC_INCLUDE}
                          ${SNAKE_BACK_SRC_INCLUDE})

add_executable(${SNAKE_CLI} ${SNAKE_CLI_SRC_INCLUDE})
set_target_properties(
  ${SNAKE_CLI} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                          "${CMAKE_SOURCE_DIR}/${INSTALL_DIR}")

target_compile_options(${SNAKE_CLI} PRIVATE -DSNAKE -DCLI -Wall -Werror -Wextra
                                            -lncursesw)

target_link_libraries(${SNAKE_CLI} PRIVATE Curses::Curses
                                           snake_back_lib_dsnake_dcli)
add_custom_target(
  ${PLAY_SNAKE_CLI}
  COMMAND "${CMAKE_SOURCE_DIR}/${INSTALL_DIR}/${SNAKE_CLI}"
  DEPENDS ${SNAKE_CLI})

set(SNAKE_CLI_ON FALSE)
