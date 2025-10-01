#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QString>
#include <QVBoxLayout>

#include "app_config.hpp"

namespace s21 {
// Основное окно игры
class GameWidget : public QWidget {
  Q_OBJECT

 public:
  explicit GameWidget(QWidget *parent) : QWidget(parent) {
    Connections();
    InfoDraw(this);
  }

  /** @brief Создание сигналов исходя из того какая клавиша была нажата */
  void keyPressEvent(QKeyEvent *Kevent) override;
#ifdef SNAKE
  /** @brief Создание сигналов исходя из того какая клавиша была отжата */
  void keyReleaseEvent(QKeyEvent *Kevent) override;
#endif
  void InfoDraw(GameWidget *game_w);
  void InfoLabelsDraw(GameInfo_t &g_info);
  void UpdateInfoFun();

 private:
  void Connections();

  // Painters
  /** @brief Рисование основных элементов приложения и объектов модели */
  void paintEvent(QPaintEvent *event) override;

  /** @brief Рисование объектов модели Змейки */
  void PaintSnakeGameFieldPxs(QPainter &painter, int &px, size_t &i, size_t &j);
#ifdef TETRIS
  /** @brief Рисование тетромино */
  void PaintTetrisGameFieldPxs(QPainter &painter, int &px, size_t &i,
                               size_t &j);

  /** @brief Рисование поля следующей фигуры в Тетрисе*/
  void PaintTetrisNextField(QPainter &painter, GameInfo_t &g_info);

  /** @brief Выбор цвета кисточки для рисования тетромино */
  void TetrisChooseBrush(QBrush &brush, int &px);
#endif

  // Variables
  QVBoxLayout *info_lay;
  QLabel *level;
  QLabel *score;
  QLabel *highscore;
  bool hold_;

  // Timers
  QTimer *update_freq_timer_;  // ← таймер обновления экрана
  QTimer *back_update_freq_timer_;  // ← таймер обновления информации о модели
 signals:
  void DeviceInputFixed(UserAction_t action, bool hold);
 private slots:
  void TransmiteSignal(UserAction_t action, bool hold);
  void BackUpdate();
  void UpdateInfo();
};
}  // namespace s21

#endif