#include "../include/view.hpp"
#include <iostream>

#ifdef TETRIS
void s21::GameWidget::TetrisChooseBrush(QBrush &brush, int &px) {
  if (px == PixelCode_t::RedIMvg || px == PixelCode_t::RedIStc) {
    brush = {"#FF0000"};
  }
  if (px == PixelCode_t::GreenLMvg || px == PixelCode_t::GreenLStc) {
    brush = {"#006400"};
  }
  if (px == PixelCode_t::YellowZMvg || px == PixelCode_t::YellowZStc) {
    brush = {"#FFD700"};
  }
  if (px == PixelCode_t::BlueJMvg || px == PixelCode_t::BlueJStc) {
    brush = {"#000080"};
  }
  if (px == PixelCode_t::MagentaOMvg || px == PixelCode_t::MagentaOStc) {
    brush = {"#FF69B4"};
  }
  if (px == PixelCode_t::CyanSMvg || px == PixelCode_t::CyanSStc) {
    brush = {"#00FFFF"};
  }
  if (px == PixelCode_t::WhiteTMvg || px == PixelCode_t::WhiteTStc) {
    brush = {"#FFFFFF"};
  }
}
#endif

void s21::GameWidget::paintEvent(QPaintEvent *event) {
  // event = nullptr;
#ifdef SNAKE
  GameInfo_t g_info = s21::Controller::updateCurrentState();
#elif TETRIS
  GameInfo_t g_info = updateCurrentState();
#endif

  QPainter painter;
  painter.begin(this);

  // Границы игрового поля
  painter.drawRect(GAMEFIELD_X, GAMEFIELD_Y, GAMEFIELD_W, GAMEFIELD_H);

  // Границы поля с информацией
  painter.drawRect(INFO_X, INFO_Y, INFO_W, INFO_H);

  for (size_t i = 0; i < GAMEFIELD_H / MULT; ++i) {
    for (size_t j = 0; j < GAMEFIELD_W / MULT; ++j) {
      painter.drawRect(GAMEFIELD_X + j * MULT, GAMEFIELD_Y + i * MULT, MULT,
                       MULT);
#ifdef SNAKE
      if (g_info.field[i][j] == s21::PxCode::Snake) {
        painter.fillRect(GAMEFIELD_X + j * MULT + 1, GAMEFIELD_Y + i * MULT + 1,
                         MULT - 1, MULT - 1, QBrush{"#00FFFF"});
      } else if (g_info.field[i][j] == s21::PxCode::Apple) {
        painter.fillRect(GAMEFIELD_X + j * MULT + 1, GAMEFIELD_Y + i * MULT + 1,
                         MULT - 1, MULT - 1, QBrush{"#FF0000"});
      }
#elif TETRIS
      if (g_info.field != NULL) {
        QBrush brush;
        TetrisChooseBrush(brush, g_info.field[i][j]);
        painter.fillRect(GAMEFIELD_X + j * MULT + 1, GAMEFIELD_Y + i * MULT + 1,
                         MULT - 1, MULT - 1, brush);
      }
#endif
    }
  }

#ifdef TETRIS
  if (g_info.field != NULL) {

    for (size_t i = 0; i < NEXT_H / MULT; ++i) {
      for (size_t j = 0; j < NEXT_W / MULT; ++j) {
        painter.drawRect(NEXT_X + j * MULT, NEXT_Y + i * MULT, MULT, MULT);
        QBrush brush;
        TetrisChooseBrush(brush, g_info.next[i][j]);
        painter.fillRect(NEXT_X + j * MULT + 1, NEXT_Y + i * MULT + 1, MULT - 1,
                         MULT - 1, brush);
      }
    }
  }
#endif

  painter.end();
}
