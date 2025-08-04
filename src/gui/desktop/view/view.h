#ifndef VIEW_H_
#define VIEW_H_

#include <QApplication>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QTimer>
#include <QWidget>

#include "../../../brick_game/snake/controller/controller.h"
#include "../../../brick_game/snake/data_types.h"
#include "app.h"

namespace s21 {
class View {
public:
  class App : public QObject {
  public:
    void AppObj(int argc, char *argv[]);

  private:
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
    signals:
      void DeviceInputFixed(bool hold);
      // void DeviceInputFixed(UserAction_t action, bool hold);
    private slots:
      void TransmiteSignal(bool hold);
      // void TransmiteSignal(UserAction_t action, bool hold);
    };
  };
};
} // namespace s21

#endif