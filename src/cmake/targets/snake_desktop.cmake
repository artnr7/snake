set(SNAKE_DESKTOP snake_desktop)
set(PLAY_SNAKE_DESKTOP play_${SNAKE_DESKTOP})

include(cmake/srcs/desktop_gui.cmake)
include(cmake/make_libs/snake_back_lib.cmake)

set(SNAKE_DESKTOP_SRC_INCLUDE play/desktop.cc ${DESKTOP_SRC_INCLUDE})

add_executable(${SNAKE_DESKTOP} ${SNAKE_DESKTOP_SRC_INCLUDE})

target_compile_options(${SNAKE_DESKTOP} PRIVATE -DSNAKE -Wall -Werror -Wextra)
set(CMAKE_AUTOMOC ON)

set_target_properties(
  ${SNAKE_DESKTOP}
  PROPERTIES AUTOMOC ON
             AUTORCC ON
             AUTOUIC ON)

target_link_libraries(${SNAKE_DESKTOP} PRIVATE Qt5::Core Qt5::Widgets
                                               snake_back_lib_dsnake)

add_custom_target(
  ${PLAY_SNAKE_DESKTOP}
  COMMAND $<TARGET_FILE:${SNAKE_DESKTOP}>
  DEPENDS ${SNAKE_DESKTOP})
