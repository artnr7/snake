#ifndef APP_H_
#define APP_H_

#include "app_config.h"
#include "gamewidget.h"

namespace s21 {
class App : public QObject {
public:
  void AppObj(int argc, char *argv[]);

private:
  s21::GameWidget *GameWidgetptr;
};
} // namespace s21

#endif