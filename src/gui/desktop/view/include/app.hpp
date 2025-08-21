#ifndef APP_H_
#define APP_H_

#include "app_config.hpp"
#include "gamewidget.hpp"

namespace s21 {
class App : public QApplication {
  Q_OBJECT
 public:
  App(int argc, char *argv[]);
  void Config(s21::GameWidget *game_w);

 private:
  QTimer *update_timer_;
  void Connections();
 signals:
  void AppClose();
 private slots:
  void Exit();
};
}  // namespace s21

#endif