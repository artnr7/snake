# SNAKE
SNAKE_BACK_CC_FILES := $(shell find brick_game/snake -name '*.c') 
SNAKE_BACK_HPP_FILES := $(shell find brick_game/snake -name '*.h')
SNAKE_BACK_OBJ_FILES := $(patsubst %.c, $(SNAKE_OBJ_FILES_DIR)/%.o, $(SNAKE_BACK_C_FILES))

SNAKE_FRONT_C_FILES := $(shell find gui/cli -name '*.c') 
SNAKE_FRONT_H_FILES := $(shell find gui/cli -name '*.c')
SNAKE_FRONT_OBJ_FILES := $(patsubst %.c, $(SNAKE_OBJ_FILES_DIR)/%.o, $(SNAKE_FRONT_C_FILES))

SNAKE_TEST_FILES := $(wildcard $(SNAKE_TEST_DIR)/*.c)