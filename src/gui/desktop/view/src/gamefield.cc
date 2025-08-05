#include "../include/view.h"

void s21::GameWidget::paintEvent(QPaintEvent *event) {
  GameInfo_t g_info = s21::Controller::updateCurrentState();

  QPainter painter;
  painter.begin(this);

  // // Границы игрового поля
  // painter.drawRect(GAMEFIELD_X, GAMEFIELD_Y, GAMEFIELD_W, GAMEFIELD_H);

  // Границы поля с информацией
  painter.drawRect(INFO_X, INFO_Y, INFO_W, INFO_H);

  for (size_t i = 0; i < GAMEFIELD_H / MULT; ++i) {
    for (size_t j = 0; j < GAMEFIELD_W / MULT; ++j) {
      painter.drawRect(GAMEFIELD_X + j * MULT, GAMEFIELD_Y + i * MULT, MULT,
                       MULT);

      if (g_info.field[i][j] == s21::PxCode::Snake) {
        painter.fillRect(GAMEFIELD_X + j * MULT + 1, GAMEFIELD_Y + i * MULT + 1,
                         MULT - 1, MULT - 1, QBrush{"#00FFFF"});
      } else if (g_info.field[i][j] == s21::PxCode::Apple) {
        painter.fillRect(GAMEFIELD_X + j * MULT + 1, GAMEFIELD_Y + i * MULT + 1,
                         MULT - 1, MULT - 1, QBrush{"#FF0000"});
      } else {
      }
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