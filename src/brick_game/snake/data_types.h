#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;    // ← игровое поле
  int **next;     // ← следующая фигура в Тетрисе
  int score;      // ← счёт
  int high_score; // ← рекорд счёта
  int level;      // ← уровень сложности
  int speed;      // ← скорость
  int pause;      // ← состояние игры

} GameInfo_t;

#endif