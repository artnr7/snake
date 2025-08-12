#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#include <QApplication>
#include <QKeyEvent>
#include <QLabel>
#include <QPainter>
#include <QPalette>
#include <QTimer>
#include <QWidget>

#ifdef TETRIS
#include "../../../brick_game/tetris/backend.h"
#elif SNAKE
#include "../../../brick_game/data_types/data_types.h"
#include "../../../brick_game/snake/controller/controller.hpp"
#endif

/*------------------→ MISC ←---------------- */
#define INDENT_Y 10
#define INDENT_X 10

#define MULT 40

#define FRAME_DISTANCE 5

/*------------------→ GAMEFIELD ←---------------- */
#define GAMEFIELD_Y INDENT_Y
#define GAMEFIELD_X INDENT_X
#define GAMEFIELD_H (20 * MULT)
#define GAMEFIELD_W (10 * MULT)

/*------------------→ INFO FIELD ←---------------- */
#define INFO_Y INDENT_Y
#define INFO_X (INDENT_X + GAMEFIELD_W + FRAME_DISTANCE)
#define INFO_H GAMEFIELD_H
#define INFO_W (GAMEFIELD_W / 2)

/*------------------→ APP ←---------------- */
#define APP_H (INDENT_Y + GAMEFIELD_H + INDENT_Y)
#define APP_W (INDENT_X + GAMEFIELD_W + FRAME_DISTANCE + INFO_W + INDENT_X)

/*------------------→ NEXT ←---------------- */
#define NEXT_Y (INFO_Y + INDENT_Y * 33)
#define NEXT_X (INFO_X + INDENT_X + 5)
#define NEXT_H (2 * MULT)
#define NEXT_W (4 * MULT)

#endif