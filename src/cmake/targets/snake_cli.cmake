set(SNAKE_CLI snake_cli)
set(PLAY_SNAKE_CLI play_${SNAKE_CLI})

include(cmake/srcs/snake_back.cmake)
include(cmake/srcs/cli_gui.cmake)
