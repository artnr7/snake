#include "../app.h"
#include "../view.h"

void s21::View::App::GameWidget::paintEvent(QPaintEvent *event) {
  QPainter painter;
  painter.begin(this);

  // Игровое поле
  painter.drawRect(GAMEFIELD_X, GAMEFIELD_Y, GAMEFIELD_W, GAMEFIELD_H);

  // Игровая информация
  painter.drawRect(INFO_X, INFO_Y, INFO_W, INFO_H);

  for (size_t i = 0; i < GAMEFIELD_H / MULT; ++i) {
    for (size_t j = 0; j < GAMEFIELD_W / MULT; ++j) {
      painter.drawRect(GAMEFIELD_X + j * MULT, GAMEFIELD_Y + i * MULT, MULT,
                       MULT);
    }
  }

#ifdef TETRIS
  for (size_t i = 0; i < NEXT_H / MULT; ++i) {
    for (size_t j = 0; j < NEXT_W / MULT; ++j) {
      painter.drawRect(NEXT_X + j * MULT, NEXT_Y + i * MULT, MULT, MULT);
    }
  }
#endif

  painter.end();
}