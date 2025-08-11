file(GLOB CONTROLLER_SRC "brick_game/snake/controller/*.cc")

if(SNAKE_CLI_ON)
  file(GLOB CONTROLLER_INCLUDE "brick_game/snake/controller/*.h")
else()
  file(GLOB CONTROLLER_INCLUDE "brick_game/snake/controller/controller.h")
endif()

file(GLOB MODEL_SRC "brick_game/snake/model/src/*.cc")
file(GLOB MODEL_INCLUDE "brick_game/snake/model/include/*.h")

file(GLOB MODEL_SNAKE_SRC "brick_game/snake/model/snake_anim/*.cc")
file(GLOB MODEL_SNAKE_INCLUDE "brick_game/snake/model/snake_anim/*.hpp")

set(SNAKE_BACK_SRC_INCLUDE
    ${CONTROLLER_SRC} ${CONTROLLER_INCLUDE} ${MODEL_SRC} ${MODEL_INCLUDE}
    ${MODEL_SNAKE_SRC} ${MODEL_SNAKE_INCLUDE})
