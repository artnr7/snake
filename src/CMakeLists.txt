# add_compile_options("-Wno-dev")

cmake_minimum_required(VERSION 3.18)

project(
  brickgame
  VERSION 1.0.0
  LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# glob_vars
include(cmake/glob_vars.cmake)

# find_packages
include(cmake/find_packages/tests.cmake)
include(cmake/find_packages/qt.cmake)
include(cmake/find_packages/curses.cmake)

# snake_desktop
include(cmake/targets/snake_desktop.cmake)

# tetris_cli
include(cmake/targets/tetris_cli.cmake)

# tetris_desktop
include(cmake/targets/tetris_desktop.cmake)

include(cmake/formatting/CMakeFormat.cmake)
include(cmake/formatting/ClangFormat.cmake)
