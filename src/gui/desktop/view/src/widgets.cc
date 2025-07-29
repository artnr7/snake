#include "../app.h"
#include "../view.h"

void s21::View::AppWidget::paintEvent(QPaintEvent *event) {
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

  painter.end();
}