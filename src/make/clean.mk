###--------→ УДАЛЕНИЕ ФАЙЛОВ ←------------------------------------------------------------###

FILES_TO_DEL = $(TETRIS_TEST_EXE_FILE) $(TETRIS_LIB_FILE)\
 $(TETRIS_BACK_OBJ_FILES) $(TETRIS_GCOV_FILES) doxygen $(TETRIS_INSTALL_DIR)\
 *.o $(tetris_cli_EXE_FILE) tetris-1.0.tar.gz $(TETRIS_GCOV_DIRS)

clean: 
	@rm -rf $(FILES_TO_DEL) build
	@echo "Clean done"