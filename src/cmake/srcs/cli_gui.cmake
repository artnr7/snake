file(GLOB CLI_GUI_SRC "gui/cli/*.c" "gui/cli/src/*.c")
file(GLOB CLI_GUI_INCLUDE "gui/cli/*.h" "gui/cli/include/*.h")

set(CLI_GUI_SRC_INCLUDE ${CLI_GUI_SRC} ${CLI_GUI_INCLUDE})
# set(CLI_GUI_SRC_INCLUDE)
