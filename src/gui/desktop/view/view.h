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
  class App : public QObject {
    Q_OBJECT
  public:
    App() {}

    void AppObj(int argc, char *argv[]);

  private:
    class GameWidget : public QWidget {
      void paintEvent(QPaintEvent *event) override;
    };
    void InfoDraw(GameWidget *game_w);
    //   GameInfo_t vs_info_;

  signals:
    void DeviceInput();

  private slots:

    void DeviceInput();
  };
};
} // namespace s21

#endif