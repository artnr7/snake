# 1 правило моих проектов → помечать концы названий пользовательских директорий приставкой _dir 
# 2 перед изменением Мейкфайла запушить изменения в Гитлаб

###--------→ СБОРКА И КОМПИЛЯЦИЯ ←------------------------------------------------------###
GCC = gcc -Wall -Werror -Wextra
GT_FLAGS = -lcheck -lm -lsubunit -lpthread
VAL_FLAGS = --tool=memcheck --leak-check=full

# директории
TETRIS_TEST_DIR := tetris_test_dir
TETRIS_INSTALL_DIR := tetris_install_dir
TETRIS_LIB_DIR := $(TETRIS_INSTALL_DIR)
TETRIS_OBJ_FILES_DIR := $(TETRIS_INSTALL_DIR)/tetris_obj_files_dir
TETRIS_DIST_DIR = tetris_dist_dir

# файлы для компиляции
TETRIS_BACK_C_FILES := $(wildcard brick_game/tetris/*.c brick_game/tetris/tetris_src/*.c\
 brick_game/tetris/tetris_src/tetris_moving/*.c) 
TETRIS_BACK_H_FILES := $(wildcard brick_game/tetris/*.h brick_game/tetris/tetris_include/*.h\
 brick_game/tetris/tetris_src/tetris_moving/*.h)
TETRIS_BACK_OBJ_FILES := $(patsubst %.c, $(TETRIS_OBJ_FILES_DIR)/%.o, $(TETRIS_BACK_C_FILES))

TETRIS_FRONT_C_FILES := $(wildcard gui/cli/*.c gui/cli/src/*.c) 
TETRIS_FRONT_H_FILES := $(wildcard gui/cli/*.h gui/cli/include/*.h)
TETRIS_FRONT_OBJ_FILES := $(patsubst %.c, $(TETRIS_OBJ_FILES_DIR)/%.o, $(TETRIS_FRONT_C_FILES))

TETRIS_TEST_FILES := $(wildcard $(TETRIS_TEST_DIR)/*.c)

# скомпилированные файлы
TETRIS_LIB_FILE = $(TETRIS_LIB_DIR)/tetris_backend.a
TETRIS_TEST_EXE_FILE = tetris_test
tetris_cli_EXE_FILE = tetris_cli


###--------→ ЦЕЛИ ←--------------------------------------------------------------------###
###--------→ УСТАНОВКА и УДАЛЕНИЕ ←---------------------------------------------------------###
all: install

install: clean clang $(TETRIS_LIB_FILE) $(TETRIS_FRONT_OBJ_FILES)

uninstall: clean

###--------→ СБОРКА БИБЛИОТЕКИ ←-----------------------------------------------------------###
$(TETRIS_LIB_FILE): $(TETRIS_BACK_OBJ_FILES)
	@mkdir -p $(TETRIS_OBJ_FILES_DIR)
	@ar rcs $@ $^
	@ranlib $@
	@echo "LIB compiled"


# КОМПИЛЯЦИЯ ОБДЖЕКТ ФАЙЛОВ 
$(TETRIS_OBJ_FILES_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(GCC) -c $< -o $@

###--------→ DVI ←--------------------------------------------------------------------###

dvi:
	doxygen

###--------→ DIST ←--------------------------------------------------------------------###
TETRIS_DIST_FILES := brick_game gui Doxyfile tetris_cli.c Makefile FSM.png tetris_test_dir

dist:
	@mkdir -p $(TETRIS_DIST_DIR)
	@cp -r $(TETRIS_DIST_FILES) $(TETRIS_DIST_DIR)
	@tar -czf tetris-1.0.tar.gz $(TETRIS_DIST_DIR)
	@rm -rf $(TETRIS_DIST_DIR)
	@echo "Archive done"

###--------→ PLAY ←--------------------------------------------------------------------###
play: clean clang $(TETRIS_LIB_FILE) $(TETRIS_FRONT_OBJ_FILES)
	@$(GCC) tetris_cli.c $(GT_FLAGS) -o $(tetris_cli_EXE_FILE)\
	 $(TETRIS_FRONT_OBJ_FILES) $(TETRIS_LIB_FILE) -lncursesw
	@./$(tetris_cli_EXE_FILE)


###--------→ ТЕСТЫ ←--------------------------------------------------------------------###

test: clean clang tetris_test_compile
	@./$(TETRIS_TEST_EXE_FILE)

test_valgrind: clean clang tetris_test_compile
	@valgrind $(VAL_FLAGS) ./$(TETRIS_TEST_EXE_FILE)

tetris_test_compile: $(TETRIS_LIB_FILE) $(TETRIS_FRONT_OBJ_FILES)
	@$(GCC) $(TETRIS_TEST_FILES) $(GT_FLAGS) -o $(TETRIS_TEST_EXE_FILE)\
	 $(TETRIS_FRONT_OBJ_FILES) $(TETRIS_LIB_FILE) -lncursesw
	@echo "Test compiled"

###--------→ GCOV ←--------------------------------------------------------------------###
TETRIS_GCOV_DIRS := coverage_report gcov_report_dir coverage.info

gcov_report: clean 
	@mkdir gcov_report_dir
	@$(GCC) $(TETRIS_BACK_C_FILES) $(TETRIS_TEST_FILES) $(GT_FLAGS)	--coverage -o gcov_report_dir/gcov_test
	./gcov_report_dir/gcov_test
	geninfo --ignore-errors mismatch --ignore-errors gcov . -o coverage.info
	genhtml coverage.info -o coverage_report
	@echo "GCOV done"

###--------→ УДАЛЕНИЕ ФАЙЛОВ ←------------------------------------------------------------###

FILES_TO_DEL = $(TETRIS_TEST_EXE_FILE) $(TETRIS_LIB_FILE)\
 $(TETRIS_BACK_OBJ_FILES) $(TETRIS_GCOV_FILES) doxygen $(TETRIS_INSTALL_DIR)\
 *.o $(tetris_cli_EXE_FILE) tetris-1.0.tar.gz $(TETRIS_GCOV_DIRS)

clean: 
	@rm -rf $(FILES_TO_DEL)
	@echo "Clean done"

###--------→ CLANG ←---------------------------------------------------------------###
# файлы для Clang
TETRIS_CLANG_FILES = $(TETRIS_BACK_C_FILES) $(TETRIS_BACK_H_FILES)\
$(TETRIS_FRONT_C_FILES) $(TETRIS_FRONT_H_FILES) $(TETRIS_TEST_FILES) tetris_cli.c

clang:
	@cp ../materials/linters/.clang-format . 
	@clang-format -i $(TETRIS_CLANG_FILES)
	@rm .clang-format
	@echo "Clang done"

###--------→ CPPCHECK ←---------------------------------------------------------------###
cppcheck:
	@cppcheck --enable=all --suppress=missingInclude .

###--------→ GDB ←---------------------------------------------------------------###
g: clean clang $(TETRIS_LIB_FILE) $(TETRIS_FRONT_OBJ_FILES)
	@$(GCC) tetris_cli.c $(GT_FLAGS) -o $(tetris_cli_EXE_FILE)\
	$(TETRIS_FRONT_OBJ_FILES) $(TETRIS_LIB_FILE) -lncursesw
	@gdb --tty=/dev/pts/5 -tui -x .gdbinit $(tetris_cli_EXE_FILE)

###--------→ CMAKE ←---------------------------------------------------------------###
# FILES:= $(shell find . -name '*.cc')

c: 
	@cmake-format -i cmake/*.cmake cmake/find_packages/*.cmake\
	 cmake/srcs/*.cmake CMakeLists.txt
	@find . -name '*.cc' -exec clang-format -i {} +
	@echo "Format done."