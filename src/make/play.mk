###--------→ PLAY ←--------------------------------------------------------------------###
PLAY_MAIN_FILES := play

play_tetris_cli: clean clang $(TETRIS_LIB_FILE) $(CLI_OBJ_FILES)
	@$(GCC) -DTETRIS PLAY_MAIN_FILES/cli.c $(CLI_OBJ_FILES) -o $(TETRIS_CLI_EXE_FILE)\
	  -lncursesw $(TETRIS_LIB_FILE) 
	@./$(TETRIS_CLI_EXE_FILE)

play_tetris_desktop: clean clang $(TETRIS_LIB_FILE) $(DESKTOP_OBJ_FILES)
	@$(GCC) -DTETRIS PLAY_MAIN_FILES/desktop.c $(DESKTOP_OBJ_FILES) -o\
	$(TETRIS_DESKTOP_EXE_FILE) $(TETRIS_LIB_FILE) 
	@./$(TETRIS_DESKTOP_EXE_FILE)

play_snake_cli: clean clang $(TETRIS_LIB_FILE) $(CLI_OBJ_FILES)
	@$(GCC) -DSNAKE -DCLI PLAY_MAIN_FILES/cli.c $(CLI_OBJ_FILES) -o $(TETRIS_CLI_EXE_FILE)\
	-lncursesw $(TETRIS_LIB_FILE) 
	@./$(TETRIS_CLI_EXE_FILE)

