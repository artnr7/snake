#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include "app_config.hpp"
#include <QString>
#include <QVBoxLayout>

namespace s21 {
// Основное окно игры
class GameWidget : public QWidget {
  Q_OBJECT

public:
  explicit GameWidget(QWidget *parent = nullptr);

  void keyPressEvent(QKeyEvent *Kevent) override;
#ifdef SNAKE
  void keyReleaseEvent(QKeyEvent *Kevent) override;
#endif
  void InfoDraw(GameWidget *game_w);
  void UpdateInfoFun();

private:
  void Connections();

  // Painters
  void paintEvent(QPaintEvent *event) override;
  void TetrisChooseBrush(QBrush &brush, int &px);
  bool hold_;

  // Variables
  QVBoxLayout *info_lay;
  QLabel *level;
  QLabel *score;
  QLabel *highscore;

  // timers
  QTimer *update_freq_timer_;
  QTimer *back_update_freq_timer_;
signals:
  void DeviceInputFixed(UserAction_t action, bool hold);
private slots:
  void TransmiteSignal(UserAction_t action, bool hold);
  void BackUpdate();
  void UpdateInfo();
};
} // namespace s21

#endif