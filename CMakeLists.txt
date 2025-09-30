cmake_minimum_required(VERSION 3.18)

project(
  brickgame
  VERSION 2.0.0
  LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# glob_vars
include(cmake/utils/glob_vars.cmake)

# single_use
include(cmake/utils/single_use.cmake)

# find_packages
include(cmake/find_packages/tests.cmake)
include(cmake/find_packages/qt.cmake)
include(cmake/find_packages/curses.cmake)

# ############################ PLAY

# snake_cli
include(cmake/targets/play/snake_cli.cmake)

# tetris_cli
include(cmake/targets/play/tetris_cli.cmake)

# snake_desktop
include(cmake/targets/play/snake_desktop.cmake)

# tetris_desktop
include(cmake/targets/play/tetris_desktop.cmake)

# ############################# UNINSTALL

include(cmake/targets/Uninstall.cmake)

# ############################# TESTS

include(cmake/tests/Snake.cmake)
include(cmake/tests/Tetris.cmake)

# ############################# COVERAGE
include(cmake/targets/Coverage.cmake)
