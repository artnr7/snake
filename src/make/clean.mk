###--------→ УДАЛЕНИЕ ФАЙЛОВ ←------------------------------------------------------------###

FILES_TO_DEL =  $(TETRIS_LIB_FILE)\
 $(TETRIS_BACK_OBJ_FILES) $(TETRIS_GCOV_FILES) doxygen $(TETRIS_INSTALL_DIR)\
 *.o tetris-1.0.tar.gz $(TETRIS_GCOV_DIRS) build

FILES_TO_DEL := $(TETRIS_TEST_EXE_FILE) ${SNAKE_TEST_EXE_FILE}\
 ${TETRIS_CLI_EXE_FILE} ${TETRIS_DESKTOP_EXE_FILE}\
 ${SNAKE_CLI_EXE_FILE} ${SNAKE_DESKTOP_EXE_FILE}\
 doxygen build *.o

clean: 
	@rm -rf $(FILES_TO_DEL)
	@echo "Clean done"