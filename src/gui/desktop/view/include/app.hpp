#ifndef APP_H_
#define APP_H_

#include "app_config.hpp"
#include "gamewidget.hpp"

namespace s21 {
class App : public QObject {
public:
  void AppObj(int argc, char *argv[]);
  void Config(s21::GameWidget *game_w);

private:
  s21::GameWidget *GameWidget;
};
} // namespace s21

#endif