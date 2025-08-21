# КОМПИЛЯЦИЯ ОБДЖЕКТ ФАЙЛОВ 
$(TETRIS_OBJ_FILES_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(GCC) -c $< -o $@