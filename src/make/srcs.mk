# файлы для компиляции

DATA_TYPES_FILES := brick_game/data_types/data_types.h
# TETRIS
TETRIS_BACK_C_FILES := $(shell find brick_game/tetris -name '*.c') 
TETRIS_BACK_H_FILES := $(shell find brick_game/tetris -name '*.h') ${DATA_TYPES_FILES}
TETRIS_BACK_FILES := ${TETRIS_BACK_C_FILES} ${TETRIS_BACK_H_FILES} 
TETRIS_BACK_OBJ_FILES := $(patsubst %.c, $(TETRIS_BUILD_FILES_DIR)/%.o, $(TETRIS_BACK_C_FILES))

TETRIS_TEST_FILES := $(wildcard $(TETRIS_TEST_DIR)/*.c)

# SNAKE
SNAKE_BAKC_H_FILES := brick_game/snake/controller/controller_wrapper_for_c.h
SNAKE_BACK_CC_FILES := $(shell find brick_game/snake -name '*.cc') 
SNAKE_BACK_HPP_FILES := $(shell find brick_game/snake -name '*.hpp') ${DATA_TYPES_FILES}
SNAKE_BACK_FILES := ${SNAKE_BACK_CC_FILES} ${SNAKE_BACK_HPP_FILES} 

SNAKE_DESKTOP_BACK_FILES := ${SNAKE_BACK_FILES}
SNAKE_CLI_BACK_FILES := ${SNAKE_BACK_FILES} ${SNAKE_BACK_H_FILES}
SNAKE_DESKTOP_OBJ_FILES := $(patsubst %.c, $(SNAKE_DESKTOP_BUILD_FILES_DIR)/%.o, $(SNAKE_DESKTOP_BACK_FILES))
SNAKE_CLI_OBJ_FILES := $(patsubst %.c, $(SNAKE_CLI_BUILD_FILES_DIR)/%.o, $(SNAKE_CLI_BACK_FILES))

SNAKE_TEST_FILES := $(wildcard $(SNAKE_TEST_DIR)/*.cc)

CLI_C_FILES := $(shell find gui/cli -name '*.c') 
CLI_H_FILES := $(shell find gui/cli -name '*.h')
CLI_FILES := ${CLI_C_FILES} ${CLI_H_FILES}
CLI_OBJ_FILES := $(patsubst %.c, $(CLI_BUILD_FILES_DIR)/%.o, $(CLI_C_FILES))

DESKTOP_CC_FILES := $(shell find gui/desktop -name '*.cpp') 
DESKTOP_HPP_FILES := $(shell find gui/desktop -name '*.hpp')
DESKTOP_FILES := ${DESKTOP_CC_FILES} ${DESKTOP_HPP_FILES}
DESKTOP_OBJ_FILES := $(patsubst %.cc, $(DESKTOP_BUILD_FILES_DIR)/%.o, $(DESKTOP_CC_FILES))
