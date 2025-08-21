# файлы для компиляции
# TETRIS
TETRIS_BACK_C_FILES := $(shell find brick_game/tetris -name '*.c') 
TETRIS_BACK_H_FILES := $(shell find brick_game/tetris -name '*.h')
TETRIS_BACK_OBJ_FILES := $(patsubst %.c, $(TETRIS_OBJ_FILES_DIR)/%.o, $(TETRIS_BACK_C_FILES))

TETRIS_FRONT_C_FILES := $(shell find gui/cli -name '*.c') 
TETRIS_FRONT_H_FILES := $(shell find gui/cli -name '*.c')
TETRIS_FRONT_OBJ_FILES := $(patsubst %.c, $(TETRIS_OBJ_FILES_DIR)/%.o, $(TETRIS_FRONT_C_FILES))

TETRIS_TEST_FILES := $(wildcard $(TETRIS_TEST_DIR)/*.c)
