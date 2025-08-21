###--------→ СБОРКА И КОМПИЛЯЦИЯ ←------------------------------------------------------###
ER_FLAGS = -Wall -Werror -Wextra
GCC = gcc ${ER_FLAGS}
GPP = g++ ${ER_FLAGS}
TETRIS_TEST_FLAGS = -lcheck -lm -lsubunit -lpthread
VALGRIND_FLAGS = --tool=memcheck --leak-check=full