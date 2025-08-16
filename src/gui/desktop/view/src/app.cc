#include "../include/app.hpp"

// Само приложение ↓
s21::App::App(int argc, char *argv[]) : QApplication(argc, argv) {
  Connections();
  s21::GameWidget *game_w = new s21::GameWidget();

  Config(game_w);

  game_w->show();
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

void s21::App::Connections() {
  update_timer_ = new QTimer(this);
  update_timer_->start(15);

  QApplication::connect(update_timer_, &QTimer::timeout, this, &s21::App::Exit);
  QApplication::connect(this, &s21::App::AppClose, this, &s21::App::quit);
}

void s21::App::Exit() {
  GameInfo_t g_info = {};

#ifdef TETRIS
  g_info = updateCurrentState();
#elif SNAKE
  g_info = s21::Controller::updateCurrentState();
#endif
  if (g_info.pause == Terminated || g_info.pause == GameOvered) {
    emit AppClose();
  }
}