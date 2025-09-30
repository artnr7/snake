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
/** @brief Значения клеток поля */
typedef enum { NothingSnake, Apple, Snake } PxCode;
#endif

/*------------------→ MISC ←---------------- */
#define INDENT_Y 10  // ← отступ от края по высоте
#define INDENT_X 10  // ← отступ от края по ширине

#define MULT 40  // ← множитель расстояния в пикселях для рисования

#define FRAME_DISTANCE 5

/*------------------→ GAMEFIELD ←---------------- */
#define GAMEFIELD_Y INDENT_Y  // ← положение игрового поля по y
#define GAMEFIELD_X INDENT_X  // ← положение игрового поля по x
#define GAMEFIELD_H (20 * MULT)  // ← высота игрового поля
#define GAMEFIELD_W (10 * MULT)  // ← ширина игрового поля

/*------------------→ INFO FIELD ←---------------- */
#define INFO_Y INDENT_Y  // ← положение поля с информацией по y
// Положение поля с информацией по x ↓
#define INFO_X (INDENT_X + GAMEFIELD_W + FRAME_DISTANCE)
#define INFO_H GAMEFIELD_H  // ← высота поля с информацией
#define INFO_W (GAMEFIELD_W / 2)  // ← ширина поля с информацией

/*------------------→ APP ←---------------- */
#define APP_H (INDENT_Y + GAMEFIELD_H + INDENT_Y)  // ← высота приложения
// Ширина приложения ↓
#define APP_W (INDENT_X + GAMEFIELD_W + FRAME_DISTANCE + INFO_W + INDENT_X)

#ifdef TETRIS
/*------------------→ NEXT ←---------------- */
#define NEXT_Y (INFO_Y + INDENT_Y * 33)  // ← положение поля след.тмино по y
#define NEXT_X (INFO_X + INDENT_X + 5)  // ← положение поля след.тмино по x
#define NEXT_H (2 * MULT)  // ← высота поля след.тмино
#define NEXT_W (4 * MULT)  // ← ширина поля след.тмино
#endif

#endif