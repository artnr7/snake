#include "view.h"

void s21::View::Window(int argc, char* argv[]) {
  QApplication app(argc, argv);
  QWidget window;
  window.setWindowTitle("Snake");
  window.setMinimumHeight(800);
  window.setMinimumWidth(500);

  QLabel info{&window};
  info.setText("Rules");

  FieldDraw();

  window.show();

  app.exec();
}