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

/** @param pause 1 ► пауза игры
 * @param pause NotInitialized ► самое первое состяние переменной, то
 * есть изначально не инициализировано, но уже используется
 * @param pause 2 ► состояние игры без паузы, но не самое первое
 состояние при старте, сделано это для того чтобы после снятия паузы не
 пересоздавалось поле */
typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;

} GameInfo_t;

typedef enum { NoLaunched, Launched, Paused, Terminated, GameOver } GameState;


#endif