#include "../include/tetris_frontend_utils.h"
#include <stdio.h>

/** @brief Инициализация окна ncurses */
void ncurses_init() {
  initscr(); // ◄ инициализация окна ncurses

  /* ▼ Инициализация цветовых пар */
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);

  noecho(); // ◄ отсутствие реакции на ввод пользователя
  keypad(stdscr, true); // ◄ поддержка клавиш стрелочек на клавиатуре
  timeout(1); // ◄ чтобы в случае отсутствия ввода в userinput попадал ERR
}

/** @brief Цикл для начала игры */
void start(UserAction_t *action, bool *hold) {
  /* ▼ В начале должны получить start хотя бы 1 раз */
  while (*action != Start) {
    keyboard_input(action, hold);
    start_menu();
  }
  clear();
  userInput(*action, *hold);
  rendering();
}

/** @brief Основной игровой цикл */
void gameloop(UserAction_t *action, bool *hold) {
  while (updateCurrentState().pause != Terminated &&
         updateCurrentState().pause != GameOver) {
    keyboard_input(action, hold);
    userInput(*action, *hold);
    rendering();
  }
}

/** @brief Ввод с клавиатуры */
void keyboard_input(UserAction_t *action, bool *hold) {
  switch (getch()) {
  case 's':
    *action = Start;
    break;
  case 't':
    *action = Pause;
    break;
  case 'q':
    *action = Terminate;
    break;
#ifdef SNAKE
  case KEY_UP:
    *action = Up;
    break;
#endif
  case KEY_LEFT:
    *action = Left;
    break;
  case KEY_RIGHT:
    *action = Right;
    break;
  case KEY_DOWN:
    *action = Down;
    break;
  case ' ':
    *action = Action;
    break;
  default:
    *action = ERR; // ◄ отстутствие ввода
  }

  *hold += 1; // ◄ заглушка
}

/** @brief Определение цвета тетромино по его кодам(движ. и стат.) */
int determ_color(int px) {
  /* Переиспользование переменной под другую задачу, она используется один раз,
   * и ни на что не влияет, по сути нужна еще одна чтобы записать туда цвет, но
   * я её просто переиспользовываю(такого слова нет XD) */

  if (px == RedIStc || px == RedIMvg) {
    px = Red;
  } else if (px == GreenLStc || px == GreenLMvg) {
    px = Green;
  } else if (px == YellowZStc || px == YellowZMvg) {
    px = Yellow;
  } else if (px == BlueJStc || px == BlueJMvg) {
    px = Blue;
  } else if (px == MagentaOStc || px == MagentaOMvg) {
    px = Magenta;
  } else if (px == CyanSStc || px == CyanSMvg) {
    px = Cyan;
  } else if (px == WhiteTStc || px == WhiteTMvg) {
    px = White;
  } else if (px == Nothing) {
    px = DefaultColor;
  }
  return px;
}
