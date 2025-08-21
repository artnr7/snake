#ifndef DATA_TYPES_H_
#define DATA_TYPES_H_

/*----------→ DEFINES ←---------- */
#define TMINO_QTY 7    // ◄ Кол-во видов тетромино
#define FIELD_H 20     // ◄ Высота игрового поля
#define FIELD_W 10     // ◄ Ширина игрового поля
#define FIELD_H_HALF 9 // ◄ Половина высоты поля(имеет смысл индекс внутри)
#define FIELD_W_HALF 4 // ◄ Половина ширины поля(имеет смысл индекс внутри)

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
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;

} GameInfo_t;

typedef enum { NoLaunched, Launched, Paused, Terminated, GameOvered } GameState;

#endif