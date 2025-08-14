file(GLOB CONTROLLER_SRC "brick_game/snake/controller/*.cc")

if(SNAKE_CLI_ON)
  message(STATUS "=222=={{{===${SNAKE_CLI_ON}")
  file(GLOB CONTROLLER_INCLUDE
       "brick_game/snake/controller/controller_wrapper_for_c.h"
       "brick_game/snake/controller/controller.hpp")
else()
  file(GLOB CONTROLLER_INCLUDE "brick_game/snake/controller/controller.hpp")
endif()

file(GLOB MODEL_SRC "brick_game/snake/model/src/*.cc")
file(GLOB MODEL_INCLUDE "brick_game/snake/model/include/*.hpp")

file(GLOB MODEL_SNAKE_SRC "brick_game/snake/model/snake_anim/*.cc")
file(GLOB MODEL_SNAKE_INCLUDE "brick_game/snake/model/snake_anim/*.hpp")

# file(GLOB DATA_TYPES_INCLUDE "brick_game/data_types/data_types.h")
file(GLOB DATA_TYPES_INCLUDE)

set(SNAKE_BACK_SRC_INCLUDE
    ${CONTROLLER_SRC}
    ${CONTROLLER_INCLUDE}
    ${MODEL_SRC}
    ${MODEL_INCLUDE}
    ${MODEL_SNAKE_SRC}
    ${MODEL_SNAKE_INCLUDE}
    ${DATA_TYPES_INCLUDE})
