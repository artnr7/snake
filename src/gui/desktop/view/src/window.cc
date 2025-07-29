#include "../app.h"
#include "../view.h"

void s21::View::Window(int argc, char* argv[]) {
  QApplication app(argc, argv);
  AppWidget field_w;

  
  field_w.setFixedSize(APP_W, APP_H);
  field_w.setWindowTitle("Snake");
  
  InfoDraw(field_w);
  
  field_w.show();

  app.exec();
}