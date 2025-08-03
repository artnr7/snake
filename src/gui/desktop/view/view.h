#ifndef VIEW_H_
#define VEIW_H_

#include <QApplication>
#include <QLabel>
#include <QPainter>
#include <QWidget>
#include <QKeyEvent>

#include "../../../brick_game/snake/data_types.h"
#include "../../../brick_game/snake/controller/controller.h"

namespace s21 {
class View {
public:
  class App : public QObject {
    Q_OBJECT
  public:
  explicit App(QObject *parent = nullptr);

  void KeyPressEvent(QKeyEvent *Kevent);
  private:
    void AppObj(int argc, char *argv[]);

    class GameWidget : public QWidget {
      void paintEvent(QPaintEvent *event) override;
      void InfoDraw(GameWidget *game_w);
    };
    //   GameInfo_t vs_info_;

  signals:
    void DeviceInput(UserAction_t action, bool hold);

  private slots:

    void OnDeviceInput();
  };
};
} // namespace s21

#endif