include(cmake/srcs/snake_back.cmake)
# if(NOT SNAKE_LIB_MADE)
add_library(snake_back_lib STATIC ${SNAKE_BACK_SRC_INCLUDE})
# target_include_directories(snake_back_lib PUBLIC brick_game/snake/controller
# brick_game/snake/model/include brick_game/snake/model/snake_anim
# brick_game/data_types ) set(SNAKE_LIB_MADE ON) endif()
