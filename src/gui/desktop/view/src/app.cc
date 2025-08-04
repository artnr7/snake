#include "../view.h"
#include <iostream>

s21::View::App::GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {
  QWidget::connect(this, &s21::View::App::GameWidget::DeviceInputFixed, this,
                   &s21::View::App::GameWidget::TransmiteSignal);
}

void s21::View::App::GameWidget::TransmiteSignal(bool hold) {}
// void s21::View::App::GameWidget::TransmiteSignal(UserAction_t action,
//                                                  bool hold) {

//   s21::Controller::userInput(action, hold);
//   std::cout << "Slot is activated!" << std::endl;
// }

void s21::View::App::GameWidget::keyPressEvent(QKeyEvent *Kevent) {
  switch (Kevent->key()) {
  case Qt::Key_S:
    emit s21::View::App::GameWidget::DeviceInputFixed(
                                                      false);
    break;
  case Qt::Key_T:
    emit s21::View::App::GameWidget::DeviceInputFixed(
                                                      false);
    break;
  case Qt::Key_Q:
    emit s21::View::App::GameWidget::DeviceInputFixed(
                                                      false);
    break;
  case Qt::Key_Left:
    emit s21::View::App::GameWidget::DeviceInputFixed(
                                                      false);
    break;

  case Qt::Key_Right:
    emit s21::View::App::GameWidget::DeviceInputFixed(
                                                      false);
    break;

  case Qt::Key_Up:
    emit s21::View::App::GameWidget::DeviceInputFixed( false);
    break;
  case Qt::Key_Down:
    emit s21::View::App::GameWidget::DeviceInputFixed(
                                                      false);
    break;

  case Qt::Key_Space:
    hold_ = true;
    emit s21::View::App::GameWidget::DeviceInputFixed(
                                                      hold_);
    break;
  }
}
// void s21::View::App::GameWidget::keyPressEvent(QKeyEvent *Kevent) {
//   switch (Kevent->key()) {
//   case Qt::Key_S:
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Start,
//                                                       false);
//     break;
//   case Qt::Key_T:
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Pause,
//                                                       false);
//     break;
//   case Qt::Key_Q:
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Terminate,
//                                                       false);
//     break;
//   case Qt::Key_Left:
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Left,
//                                                       false);
//     break;

//   case Qt::Key_Right:
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Right,
//                                                       false);
//     break;

//   case Qt::Key_Up:
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Up, false);
//     break;
//   case Qt::Key_Down:
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Down,
//                                                       false);
//     break;

//   case Qt::Key_Space:
//     hold_ = true;
//     emit s21::View::App::GameWidget::DeviceInputFixed(UserAction_t::Action,
//                                                       hold_);
//     break;
//   }
// }

void s21::View::App::GameWidget::keyReleaseEvent(QKeyEvent *Kevent) {
  if (Kevent->key() == Qt::Key_Space) {
    hold_ = false;
  }
}

// Само приложение
void s21::View::App::AppObj(int argc, char *argv[]) {
  QApplication app(argc, argv);
  GameWidget *game_w = new GameWidget;

  game_w->setFixedSize(APP_W, APP_H);
  game_w->setWindowTitle("Snake");

  game_w->InfoDraw(game_w);

  game_w->show();

  app.exec();
}