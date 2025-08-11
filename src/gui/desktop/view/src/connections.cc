#include "../include/view.h"

void s21::GameWidget::Connections() {
  update_freq_timer_ = new QTimer(this);
  update_freq_timer_->start(15);

  back_update_freq_timer_ = new QTimer(this);
  back_update_freq_timer_->start(15);

  QWidget::connect(update_freq_timer_, &QTimer::timeout, this,
                   QOverload<>::of(&s21::GameWidget::update));

  QWidget::connect(back_update_freq_timer_, &QTimer::timeout, this,
                   &s21::GameWidget::BackUpdate);

  QWidget::connect(this, &s21::GameWidget::DeviceInputFixed, this,
                   &s21::GameWidget::TransmiteSignal);

  QWidget::connect(update_freq_timer_, &QTimer::timeout, this,
                   &s21::GameWidget::Exit);

  QWidget::connect(back_update_freq_timer_, &QTimer::timeout, this,
                   &s21::GameWidget::UpdateInfo);
}