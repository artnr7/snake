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

find_package(
  Qt5 REQUIRED
  COMPONENTS Core Widgets
  REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(hello gui/desktop/front.cc)

target_link_libraries(hello PRIVATE Qt5::Core)
target_link_libraries(hello PRIVATE Qt5::Widgets)

add_custom_target(
  play_snake
  COMMAND ./$(CMAKE_BINARY_DIR/snake_game)
  DEPENDS ./$(CMAKE_BINARY_DIR/snake_game))
