#include "../app.h"
#include "../view.h"

void s21::View::Window(int argc, char *argv[]) {
  QApplication app(argc, argv);
  AppWidget *game_w = new AppWidget;

  game_w->setFixedSize(APP_W, APP_H);
  game_w->setWindowTitle("Snake");

  InfoDraw(game_w);

  game_w->show();

  app.exec();
}