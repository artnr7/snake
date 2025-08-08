#include "../include/view.h"

void s21::GameWidget::InfoDraw(GameWidget *field_w) {
  GameInfo_t g_info = s21::Controller::updateCurrentState();

  info_lay = new QVBoxLayout(field_w);
  info_lay->setContentsMargins(INFO_X + INDENT_X, INFO_Y + INDENT_Y, INDENT_X,
                               INDENT_Y);
  info_lay->addSpacing(INDENT_Y);

  QLabel *rules = new QLabel;
  rules->setText(
      "            TO\nSTART|PAUSE|EXIT\n           PRESS\n   S\tT       Q");
  QFont info_font("Verdana", 15, 300);
  rules->setFont(info_font);

  level = new QLabel;
  QString user_level = QString::number(g_info.level);
  level->setText("Level:" + user_level);
  level->setFont(info_font);
  level->repaint();

  score = new QLabel;
  QString user_score = QString::number(g_info.score);
  score->setText("Score:" + user_score);
  score->setFont(info_font);
  score->repaint();

  highscore = new QLabel;
  QString user_highscore = QString::number(g_info.high_score);
  highscore->setText("Highscore:" + user_highscore);
  highscore->setFont(info_font);
  highscore->repaint();

  info_lay->addWidget(rules, 0, Qt::AlignTop);
  info_lay->addSpacing(2 * INDENT_Y);

  info_lay->addWidget(level, 0, Qt::AlignTop);

  info_lay->addWidget(score, 0, Qt::AlignTop);

  info_lay->addWidget(highscore, 0, Qt::AlignTop);

#ifdef TETRIS
  QLabel *next = new QLabel;
  next->setText("       NEXT");
  next->setFont(info_font);
  info_lay->addWidget(next, 0, Qt::AlignTop);
#endif
  info_lay->addSpacing(100 * INDENT_Y);
}

void s21::GameWidget::UpdateInfoFun() {
  GameInfo_t g_info = s21::Controller::updateCurrentState();
  QString user_level = QString::number(g_info.level);
  level->setText("Level:" + user_level);

  QString user_score = QString::number(g_info.score);
  score->setText("Score:" + user_score);

  QString user_highscore = QString::number(g_info.high_score);
  highscore->setText("Highscore:" + user_highscore);
}