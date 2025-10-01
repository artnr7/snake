file(GLOB_RECURSE TETRIS_BACK_SRC "brick_game/tetris/*.c")
file(GLOB_RECURSE TETRIS_BACK_INCLUDE "brick_game/tetris/*.h")

file(GLOB DATA_TYPES_INCLUDE "brick_game/data_types/data_types.h")

set(TETRIS_BACK_SRC_INCLUDE ${TETRIS_BACK_SRC} ${TETRIS_BACK_INCLUDE}
                            ${DATA_TYPES_INCLUDE})
