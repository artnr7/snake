###--------→ СБОРКА И КОМПИЛЯЦИЯ ←------------------------------------------------------###
ER_FLAGS = -Wall -Werror -Wextra -pedantic
GCC = gcc -std=c11 ${ER_FLAGS}
GPP = g++ -std=c++20 ${ER_FLAGS}
TETRIS_TEST_FLAGS = -lcheck -lm -lsubunit -lpthread
VALGRIND_FLAGS = --tool=memcheck --leak-check=full