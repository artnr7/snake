include(cmake/srcs/snake_back.cmake)

if(SNAKE_CLI_ON)
  add_library(snake_back_lib_dsnake_dcli STATIC ${SNAKE_BACK_SRC_INCLUDE})
  target_compile_options(snake_back_lib_dsnake_dcli PRIVATE -DSNAKE -DCLI -Wall
                                                            -Werror -Wextra)
endif()

if(NOT SNAKE_CLI_ON)
  add_library(snake_back_lib_dsnake STATIC ${SNAKE_BACK_SRC_INCLUDE})
  target_compile_options(snake_back_lib_dsnake PRIVATE -DSNAKE -Wall -Werror
                                                       -Wextra)
endif()
