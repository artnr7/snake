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
  void FieldDraw();
  void InfoDraw();
  //   GameInfo_t vs_info_;
};
}  // namespace s21

#endif