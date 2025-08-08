#include "../include/view.h"

s21::GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {
  Connections();
  InfoDraw(this);
}