#ifndef VIEW_H_
#define VEIW_H_

#include <QApplication>
#include <QLabel>
#include <QPainter>
#include <QWidget>

#include "../../../brick_game/snake/data_types.h"

namespace s21 {
class View {
 public:
  //   void DeviceInput();

  void Window(int argc, char* argv[]);

 private:
  class AppWidget : public QWidget {
    void paintEvent(QPaintEvent* event) override;
  };
  void InfoDraw(AppWidget& field_w);
  //   GameInfo_t vs_info_;
};
}  // namespace s21

#endif