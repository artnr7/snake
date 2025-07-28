#include <QtWidgets>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  app.exec(); // запуск приложения 
  app.processEvents(); // запуск фонового потока
  QLabel lbl("Hello, World!");

  lbl.show();
  return app.exec();
}