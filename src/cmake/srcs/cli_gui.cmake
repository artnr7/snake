file(GLOB CLI_GUI_SRC "gui/cli/*.c" "gui/cli/src/*.c")
file(GLOB CLI_GUI_INCLUDE "gui/cli/*.h" "gui/cli/include/*.h")
file(GLOB TIMER_SRC "brick_game/tetris/src/timer.c")
file(GLOB TIMER_INCLUDE "brick_game/tetris/include/timer.h")

set(CLI_GUI_SRC_INCLUDE ${CLI_GUI_SRC} ${CLI_GUI_INCLUDE} ${TIMER_SRC}
                        ${TIMER_INCLUDE})
