#include <QVBoxLayout>

#include "../app.h"
#include "../view.h"

void s21::View::InfoDraw(AppWidget *field_w) {
  QVBoxLayout *info_lay = new QVBoxLayout(field_w);
  info_lay->setContentsMargins(INFO_X + INDENT_X, INFO_Y + INDENT_Y, INDENT_X,
                               INDENT_Y);
  info_lay->addSpacing(INDENT_Y);

  QLabel *rules = new QLabel;
  rules->setText(
      "            TO\nSTART|PAUSE|EXIT\n           PRESS\n   S\tT       Q");
  QFont info_font("Verdana", 15, 300);
  rules->setFont(info_font);

  QLabel *level = new QLabel;
  level->setText("Level:");
  level->setFont(info_font);

  QLabel *score = new QLabel;
  score->setText("Score:");
  score->setFont(info_font);

  QLabel *highscore = new QLabel;
  highscore->setText("Highscore:");
  highscore->setFont(info_font);

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