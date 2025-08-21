###--------→ СБОРКА БИБЛИОТЕКИ ←-----------------------------------------------------------###
$(TETRIS_LIB_FILE): $(TETRIS_BACK_OBJ_FILES)
	@mkdir -p $(TETRIS_OBJ_FILES_DIR)
	@ar rcs $@ $^
	@ranlib $@
	@echo "LIB compiled"
