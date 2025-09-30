#include "../include/view.hpp"

/** @brief Соединения сигналов и слотов */
void s21::GameWidget::Connections() {
  // Инициализация таймера обновления экрана ↓
  update_freq_timer_ = new QTimer(this);
  update_freq_timer_->start(15);

  // Инициализация таймера обновления модели ↓
  back_update_freq_timer_ = new QTimer(this);
  back_update_freq_timer_->start(15);

  // Обновление экрана ↓
  QWidget::connect(update_freq_timer_, &QTimer::timeout, this,
                   QOverload<>::of(&s21::GameWidget::update));

  // Обновление модели ↓
  QWidget::connect(back_update_freq_timer_, &QTimer::timeout, this,
                   &s21::GameWidget::BackUpdate);

  // Передача сигнала модели ↓
  QWidget::connect(this, &s21::GameWidget::DeviceInputFixed, this,
                   &s21::GameWidget::TransmiteSignal);

  // Вывод обновлённой информации ↓
  QWidget::connect(back_update_freq_timer_, &QTimer::timeout, this,
                   &s21::GameWidget::UpdateInfo);
}
