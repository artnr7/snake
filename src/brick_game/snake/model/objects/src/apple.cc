#include "../include/apple.h"

s21::Apple::Apple() {

  srand(time(0));
  // rand() % (b - a + 1) + a [a;b]
  apple_.cord_y_ = rand() % (19 - 0 + 1) + 0;
  apple_.cord_x_ = rand() % (9 - 0 + 1) + 0;
}