# add_compile_options("-Wno-dev")

cmake_minimum_required(VERSION 3.18)

project(
  brickgame
  VERSION 1.0.0
  LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# glob_vars
include(cmake/glob_vars.cmake)

# single_use
include(cmake/single_use.cmake)

# find_packages
include(cmake/find_packages/tests.cmake)
include(cmake/find_packages/qt.cmake)
include(cmake/find_packages/curses.cmake)

# test
set(SNAKE_CLI_ON TRUE)
file(GLOB CONTROLLER_SRC "brick_game/snake/controller/*.cc")

if(SNAKE_CLI_ON)
  message(STATUS "=222=={{{===${SNAKE_CLI_ON}")
  file(GLOB CONTROLLER_INCLUDE
       "brick_game/snake/controller/controller_wrapper_for_c.h"
       "brick_game/snake/controller/controller.hpp"
      )
else()
  file(GLOB CONTROLLER_INCLUDE "brick_game/snake/controller/controller.hpp")
endif()

file(GLOB MODEL_SRC "brick_game/snake/model/src/*.cc")
file(GLOB MODEL_INCLUDE "brick_game/snake/model/include/*.hpp")

file(GLOB MODEL_SNAKE_SRC "brick_game/snake/model/snake_anim/*.cc")
file(GLOB MODEL_SNAKE_INCLUDE "brick_game/snake/model/snake_anim/*.hpp")

file(GLOB DATA_TYPES_INCLUDE "brick_game/data_types/data_types.h")

set(SNAKE_BACK_SRC_INCLUDE
    ${CONTROLLER_SRC}
    ${CONTROLLER_INCLUDE}
    ${MODEL_SRC}
    ${MODEL_INCLUDE}
    ${MODEL_SNAKE_SRC}
    ${MODEL_SNAKE_INCLUDE}
    ${DATA_TYPES_INCLUDE})


add_library(snake_back_lib STATIC ${SNAKE_BACK_SRC_INCLUDE})


file(GLOB CLI_GUI_SRC "gui/cli/*.c" "gui/cli/src/*.c")
file(GLOB CLI_GUI_INCLUDE "gui/cli/*.h" "gui/cli/include/*.h")
file(GLOB TIMER_SRC "brick_game/tetris/src/timer.c")
file(GLOB TIMER_INCLUDE "brick_game/tetris/include/timer.h")

set(CLI_GUI_SRC_INCLUDE ${CLI_GUI_SRC} ${CLI_GUI_INCLUDE} ${TIMER_SRC}
                        ${TIMER_INCLUDE})


set(SNAKE_CLI snake_cli)
set(PLAY_SNAKE_CLI play_${SNAKE_CLI})

# set(SNAKE_CLI_SRC_INCLUDE cli.c ${CLI_GUI_SRC_INCLUDE} ${SNAKE_BACK_SRC_INCLUDE})
set(SNAKE_CLI_SRC_INCLUDE cli.c ${CLI_GUI_SRC_INCLUDE})

add_executable(${SNAKE_CLI} ${SNAKE_CLI_SRC_INCLUDE})
target_include_directories(${SNAKE_CLI} PRIVATE "brick_game/snake" "gui/cli"
                                                "brick_game/data_types")

target_link_libraries(${SNAKE_CLI} PRIVATE Curses::Curses snake_back_lib)

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

# target_link_libraries(${SNAKE_CLI} PRIVATE Curses::Curses)

add_custom_target(
  ${PLAY_SNAKE_CLI}
  COMMAND $<TARGET_FILE:${SNAKE_CLI}>
  DEPENDS ${SNAKE_CLI})

set(SNAKE_CLI_ON FALSE)

# snake_cli
# include(cmake/targets/snake_cli.cmake)

# tetris_cli include(cmake/targets/tetris_cli.cmake)

# snake_desktop include(cmake/targets/snake_desktop.cmake)

# tetris_desktop include(cmake/targets/tetris_desktop.cmake)

include(cmake/formatting/CMakeFormat.cmake)
include(cmake/formatting/ClangFormat.cmake)
