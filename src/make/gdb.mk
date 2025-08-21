###--------→ GDB ←---------------------------------------------------------------###
g: clean clang $(TETRIS_LIB_FILE) $(TETRIS_FRONT_OBJ_FILES)
	@$(GCC) tetris_cli.c $(TETRIS_TEST_FLAGS) -o $(tetris_cli_EXE_FILE)\
	$(TETRIS_FRONT_OBJ_FILES) $(TETRIS_LIB_FILE) -lncursesw
	@gdb --tty=/dev/pts/5 -tui -x .gdbinit $(tetris_cli_EXE_FILE)