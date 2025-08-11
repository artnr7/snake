set(TETRIS_DESKTOP tetris_desktop)
set(PLAY_TETRIS_DESKTOP play_${TETRIS_DESKTOP})

include(cmake/srcs/tetris_back.cmake)
include(cmake/srcs/desktop_gui.cmake)

set(TETRIS_DESKTOP_SRC_INCLUDE desktop.cc ${TETRIS_BACK_SRC_INCLUDE}
                               ${DESKTOP_SRC_INCLUDE})

add_executable(${TETRIS_DESKTOP} ${TETRIS_DESKTOP_SRC_INCLUDE})

target_compile_options(${TETRIS_DESKTOP} PRIVATE -DTETRIS)

set(CMAKE_AUTOMOC ON)

set_target_properties(
  ${SNAKE_DESKTOP}
  PROPERTIES AUTOMOC ON
             AUTORCC ON
             AUTOUIC ON)

target_link_libraries(${TETRIS_DESKTOP} PRIVATE Qt5::Core Qt5::Widgets)

add_custom_target(
  ${PLAY_TETRIS_DESKTOP}
  COMMAND $<TARGET_FILE:${TETRIS_DESKTOP}>
  DEPENDS ${TETRIS_DESKTOP})
