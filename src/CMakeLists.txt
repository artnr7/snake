# add_compile_options("-Wno-dev")

cmake_minimum_required(VERSION 3.18)

project(
  brickgame
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CURSES_NEED_NCURSES TRUE)
set(CURSES_NEED_WIDE TRUE)

include(cmake/find_packages/tests.cmake)
include(cmake/find_packages/qt.cmake)
include(cmake/find_packages/curses.cmake)

# snake_desktop
include(cmake/snake_desktop.cmake)

# tetris_cli
include(cmake/tetris_cli.cmake)

include(cmake/formatting/CMakeFormat.cmake)
include(cmake/formatting/ClangFormat.cmake)
