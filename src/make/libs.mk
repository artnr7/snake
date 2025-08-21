###--------→ СБОРКА БИБЛИОТЕКИ ←-----------------------------------------------------------###
$(TETRIS_LIB_FILE): $(TETRIS_BACK_OBJ_FILES)
	@mkdir -p $(TETRIS_BUILD_FILES_DIR)
	@ar rcs $@ $^
	@ranlib $@
	@echo "TETRIS_LIB compiled"
	
$(SNAKE_CLI_LIB_FILE): $(SNAKE_BACK_OBJ_FILES)
	@mkdir -p $(SNAKE_BUILD_FILES_DIR)
	@ar rcs $@ $^
	@ranlib $@
	@echo "SNAKE_CLI_LIB compiled"

$(SNAKE_DESKTOP_LIB_FILE): $(SNAKE_BACK_OBJ_FILES)
	@mkdir -p $(SNAKE_BUILD_FILES_DIR)
	@ar rcs $@ $^
	@ranlib $@
	@echo "SNAKE_DESKTOP_LIB compiled"
