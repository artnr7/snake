#include "view.h"

void s21::View::FieldDraw() {
  QPainter field_painter;
  field_painter.begin(this);
  
  field_painter.drawRect(0, 20, 300, 800);
}