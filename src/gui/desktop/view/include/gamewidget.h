#include "app_config.h"

namespace s21 {
// Основное окно игры
class GameWidget : public QWidget {
  Q_OBJECT

public:
  explicit GameWidget(QWidget *parent = nullptr);
  void keyPressEvent(QKeyEvent *Kevent) override;
  void keyReleaseEvent(QKeyEvent *Kevent) override;
  void InfoDraw(GameWidget *game_w);

private:
  void paintEvent(QPaintEvent *event) override;
  bool hold_;
  QTimer *update_freq_timer_;
signals:
  void DeviceInputFixed(UserAction_t action, bool hold);
private slots:
  void TransmiteSignal(UserAction_t action, bool hold);
  void Exit();
};
} // namespace s21