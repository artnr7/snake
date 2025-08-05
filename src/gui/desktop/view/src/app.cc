#include "../include/view.h"
#include <QString>
#include <iostream>

s21::GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {
  update_freq_timer_ = new QTimer(this);
  update_freq_timer_->start(15);
  QWidget::connect(update_freq_timer_, &QTimer::timeout, this,
                   QOverload<>::of(&s21::GameWidget::update));
  QWidget::connect(this, &s21::GameWidget::DeviceInputFixed, this,
                   &s21::GameWidget::TransmiteSignal);
}

void s21::GameWidget::TransmiteSignal(UserAction_t action, bool hold) {

  s21::Controller::userInput(action, hold);
  std::cout << "Slot is activated!" << std::endl;
}

void s21::GameWidget::keyPressEvent(QKeyEvent *Kevent) {
  switch (Kevent->key()) {
  case Qt::Key_S:
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Start, false);
    break;
  case Qt::Key_T:
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Pause, false);
    break;
  case Qt::Key_Q:
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Terminate, false);
    break;
  case Qt::Key_Left:
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Left, false);
    break;

  case Qt::Key_Right:
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Right, false);
    break;
  case Qt::Key_Up:
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Up, false);
    break;
  case Qt::Key_Down:
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Down, false);
    break;
  case Qt::Key_Space:
    hold_ = true;
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Action, hold_);
    break;
  }
}

void s21::GameWidget::keyReleaseEvent(QKeyEvent *Kevent) {
  if (Kevent->key() == Qt::Key_Space) {
    hold_ = false;
  }
}

// Само приложение ↓
void s21::App::AppObj(int argc, char *argv[]) {
  QApplication app(argc, argv);
  s21::GameWidget *game_w = new s21::GameWidget();

  // Размеры ↓
  game_w->setFixedSize(APP_W, APP_H);

  // Название окна ↓
  QString g_name = {};
#ifdef TETRIS
  g_name = "Tetris";
#elif SNAKE
  g_name = "Snake";
#endif
  game_w->setWindowTitle(g_name);

  // #ifdef TETRIS
  //   GameInfo_t g_info = updateCurrentState();
  // #elif SNAKE
  //   GameInfo_t g_info = s21::Controller::updateCurrentState();
  // #endif
  // Цвета ↓
  QPalette pal = game_w->palette();
  pal.setColor(QPalette::Window, Qt::gray);
  game_w->setAutoFillBackground(true);
  game_w->setPalette(pal);

  game_w->InfoDraw(game_w);

  game_w->show();

  app.exec();
}