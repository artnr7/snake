#include <locale.h>

#include "gui/cli/tetris_frontend.h"

int main() {
    setlocale(LC_ALL, "");
  tetris_gui();
  return 0;
}