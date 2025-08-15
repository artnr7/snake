set(TETRIS_DESKTOP tetris_desktop)
set(PLAY_TETRIS_DESKTOP play_${TETRIS_DESKTOP})

include(cmake/srcs/desktop_gui.cmake)
include(cmake/make_libs/tetris_back_lib.cmake)

set(TETRIS_DESKTOP_SRC_INCLUDE desktop.cc ${DESKTOP_SRC_INCLUDE})

add_executable(${TETRIS_DESKTOP} ${TETRIS_DESKTOP_SRC_INCLUDE})

target_compile_options(${TETRIS_DESKTOP} PRIVATE -DTETRIS -Wall -Werror -Wextra)

set(CMAKE_AUTOMOC ON)

set_target_properties(
  ${SNAKE_DESKTOP}
  PROPERTIES AUTOMOC ON
             AUTORCC ON
             AUTOUIC ON)

target_link_libraries(${TETRIS_DESKTOP} PRIVATE Qt5::Core Qt5::Widgets
                                                tetris_back_lib)

add_custom_target(
  ${PLAY_TETRIS_DESKTOP}
  COMMAND $<TARGET_FILE:${TETRIS_DESKTOP}>
  DEPENDS ${TETRIS_DESKTOP})
