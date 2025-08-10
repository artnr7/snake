file(GLOB CONTROLLER_SRC "brick_game/snake/controller/*.cc")
file(GLOB CONTROLLER_INCLUDE "brick_game/snake/controller/*.h")

file(GLOB MODEL_SRC "brick_game/snake/model/src/*.cc")
file(GLOB MODEL_INCLUDE "brick_game/snake/model/include/*.h")

file(GLOB MODEL_SNAKE_SRC "brick_game/snake/model/snake_anim/*.cc")
file(GLOB MODEL_SNAKE_INCLUDE "brick_game/snake/model/snake_anim/*.h")

set(SNAKE_BACK_SRC_INCLUDE
    ${CONTROLLER_SRC}
    ${CONTROLLER_INCLUDE}
    ${MODEL_SRC}
    ${MODEL_INCLUDE}
    ${MODEL_SNAKE_SRC}
    ${MODEL_SNAKE_INCLUDE})
