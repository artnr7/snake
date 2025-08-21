# КОМПИЛЯЦИЯ ОБДЖЕКТ ФАЙЛОВ 
$(TETRIS_OBJ_FILES_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(GCC) -c $< -o $@

$(SNAKE_CLI_OBJ_FILES_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	@$(GPP) -c $< -DSNAKE -DCLI -o $@

$(SNAKE_DESKTOP_OBJ_FILES_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	@$(GPP) -c $< -DSNAKE -o $@

$(CLI_OBJ_FILES_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(GCC) -c $< -DSNAKE -o $@

$(SNAKE_DESKTOP_OBJ_FILES_DIR)/%.o: %.cc
	@mkdir -p $(dir $@)
	@$(GPP) -c $< -DSNAKE -o $@
