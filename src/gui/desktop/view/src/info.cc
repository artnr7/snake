#include <QVBoxLayout>

#include "../app.h"
#include "../view.h"

void s21::View::InfoDraw(AppWidget &field_w) {
  QVBoxLayout *info = new QVBoxLayout(field_w);
  QLabel level_info{&field_w};
  level_info.setText("Level:");
  level_info.move(INFO_X + 2, INFO_Y + 5);
}