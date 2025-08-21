
###--------→ TESTS ←--------------------------------------------------------------------###

test: clean clang tetris_test_compile
	@./$(TETRIS_TEST_EXE_FILE)

test_valgrind: clean clang tetris_test_compile
	@valgrind $(VALGRIND_FLAGS) ./$(TETRIS_TEST_EXE_FILE)

tetris_test_compile: $(TETRIS_LIB_FILE) $(TETRIS_FRONT_OBJ_FILES)
	@$(GCC) $(TETRIS_TEST_FILES) $(TETRIS_TEST_FLAGS) -o $(TETRIS_TEST_EXE_FILE)\
	 $(TETRIS_FRONT_OBJ_FILES) $(TETRIS_LIB_FILE) -lncursesw
	@echo "Test compiled"