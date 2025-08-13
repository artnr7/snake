#include "../include/view.hpp"

s21::GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {
  Connections();
  InfoDraw(this);
}