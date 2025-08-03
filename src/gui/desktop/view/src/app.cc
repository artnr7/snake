#include "../app.h"
#include "../view.h"
#include <iostream>

s21::View::App::App(QObject *parent) : QObject(parent) {

  QObject::connect(this, SIGNAL(DeviceInput()), this, SLOT(OnDeviceInput()));
  emit DeviceInput();
}

void s21::View::App::DeviceInput(UserAction_t action, bool hold) {
  s21::Controller::userInput();
}

void s21::View::App::OnDeviceInput() { std::cout << "Slot is activated!"; }

void s21::View::App::KeyPressEvent(QKeyEvent *Kevent) {
  static int key = Kevent->key();
  bool hold = false;

  switch (key) {
  case Qt::Key_S:
    emit s21::View::App::DeviceInput(UserAction_t::Start, false);
    break;
  case Qt::Key_T:
    emit s21::View::App::DeviceInput(UserAction_t::Pause, false);
    break;
  case Qt::Key_Q:
    emit s21::View::App::DeviceInput(UserAction_t::Terminate, false);
    break;
  case Qt::Key_Left:
    emit s21::View::App::DeviceInput(UserAction_t::Left, false);
    break;

  case Qt::Key_Right:
    emit s21::View::App::DeviceInput(UserAction_t::Right, false);
    break;

  case Qt::Key_Up:
    emit s21::View::App::DeviceInput(UserAction_t::Up, false);
    break;
  case Qt::Key_Down:
    emit s21::View::App::DeviceInput(UserAction_t::Down, false);
    break;

  case Qt::Key_Space:
hold 
    emit s21::View::App::DeviceInput(UserAction_t::Action, hold);
    break;
  }
  static int old_key = Kevent->key();
}

// Само приложение
void s21::View::App::AppObj(int argc, char *argv[]) {
  QApplication app(argc, argv);
  GameWidget *game_w = new GameWidget;

  game_w->setFixedSize(APP_W, APP_H);
  game_w->setWindowTitle("Snake");

  InfoDraw(game_w);

  game_w->show();

  app.exec();
}