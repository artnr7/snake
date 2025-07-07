#include "../include/apple.h"

s21::Apple::Apple() { MoveApple(); }

void s21::Apple::MoveApple() {
  srand(time(0));
  // rand() % (b - a + 1) + a [a;b]
  apple_.cord_y_ = rand() % (FIELD_H - 1 - 0 + 1) + 0;
  apple_.cord_x_ = rand() % (FIELD_W - 1 - 0 + 1) + 0;
}

s21::ObjectPc &s21::Apple::GetBody() { return apple_; }
