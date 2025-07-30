add_compile_options("-Wno-dev")

cmake_minimum_required(VERSION 3.18)

project(
  snake
  VERSION 1.0.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(Check REQUIRED)
find_package(Threads REQUIRED)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# snake snake_game
set(SNAKE_GAME snake_game)
set(PLAY_SNAKE_GAME play_${SNAKE_GAME})

file(GLOB DESKTOP_SRC "gui/desktop/view/src/*.cc")
set(SNAKE_GAME_SRC snake.cc ${DESKTOP_SRC})
add_executable(${SNAKE_GAME} ${SNAKE_GAME_SRC})

target_compile_options(${SNAKE_GAME} PRIVATE -DTETRIS)

set_target_properties(
  ${SNAKE_GAME}
  PROPERTIES AUTOMOC ON
             AUTORCC ON
             AUTOUIC ON)

target_link_libraries(${SNAKE_GAME} PRIVATE Qt5::Core Qt5::Widgets)

file(GLOB_RECURSE CLANG "*.cc" "*.h")

add_custom_target(
  ${PLAY_SNAKE_GAME}
  COMMAND clang-format -i ${CLANG}
  COMMAND $<TARGET_FILE:${SNAKE_GAME}>
  DEPENDS ${SNAKE_GAME})

include(cmake/CMakeFormat.cmake)
include(cmake/ClangFormat.cmake)
