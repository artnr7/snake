#include "../include/view.hpp"

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
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Action, true);
    break;
  }
}

void s21::GameWidget::keyReleaseEvent(QKeyEvent *Kevent) {
  if (Kevent->key() == Qt::Key_Space) {
    emit s21::GameWidget::DeviceInputFixed(UserAction_t::Action, false);
  }
}
