#include "../include/view.hpp"

// Само приложение ↓
void s21::App::AppObj(int argc, char *argv[]) {
  QApplication app(argc, argv);
  s21::GameWidget *game_w = new s21::GameWidget();

  Config(game_w);

  game_w->show();

  app.exec();
}

void s21::App::Config(s21::GameWidget *game_w) {

  // Размеры ↓
  game_w->setFixedSize(APP_W, APP_H);

  // Название окна ↓
#ifdef TETRIS
  game_w->setWindowTitle((QString) "Tetris");
#elif SNAKE
  game_w->setWindowTitle((QString) "Snake");
#endif

  // Цвета ↓
  QPalette pal = game_w->palette();
  pal.setColor(QPalette::Window, Qt::gray);
  game_w->setAutoFillBackground(true);
  game_w->setPalette(pal);
}
