#ifndef __TETRIS_DATA_TYPES__
#define __TETRIS_DATA_TYPES__

#include <stdbool.h>
#include <wchar.h>

/*----------→ DEFINES ←---------- */
#define TMINO_QTY 7  // ◄ Кол-во видов тетромино
#define FLD_H 20     // ◄ Высота игрового поля
#define FLD_W 10     // ◄ Ширина игрового поля
#define FLD_W_HALF 4 // ◄ Половина ширины поля(имеет смысл индекс внутри)

#define NEXT_TMINO_H 2 // ◄ Высота матрицы для хранения тетромино
#define NEXT_TMINO_W 4 // ◄ Ширина матрицы для хранения тетромино

#define TMINO_BLKS_QTY 4 // ◄ Кол-во блоков в тетромино, всегда состоят из 4
#define TMINO_POS_QTY 4  // ◄ Кол-во поз тетромино
#define TMINO_START_Y 1 // ◄ Начальная координата созданного тетромино по верт.
#define TMINO_START_X 4 // ◄ Начальная координата созданного тетромино по гориз.

/** @brief Enum, который описывает какой код имеет пиксель в поле*/
typedef enum {
  Nothing, // ◄ ничего(отсутствие блока)

  /* Движущиеся */
  RedIStc,     // ◄ Красный I движущийся
  GreenLStc,   // ◄ Зелёный L движущийся
  YellowZStc,  // ◄ Жёлтый Z движущийся
  BlueJStc,    // ◄ Синий J движущийся
  MagentaOStc, // ◄ Фиолетовый O движущийся
  CyanSStc,    // ◄ Бирюзовый S движущийся
  WhiteTStc,   // ◄ Белый T движущийся

  /* Статичные */
  RedIMvg,     // ◄ Красный I статичный
  GreenLMvg,   // ◄ Зелёный L статичный
  YellowZMvg,  // ◄ Жёлтый Z статичный
  BlueJMvg,    // ◄ Синий J статичный
  MagentaOMvg, // ◄ Фиолетовый O статичный
  CyanSMvg,    // ◄ Бирюзовый S статичный
  WhiteTMvg    // ◄ Белый T статичный

} PixelCode_t;

/** @brief Структура тетромино */
typedef struct {
  wchar_t *shape;      // ◄ шаблон тетромино
  PixelCode_t px_code; // ◄ код пикселей тетромино
} Tetromino_t;

/** @brief Фиксирование возможности движения в функции движения влево-вправо */
typedef enum {
  NoWay,  // ◄ запрет движения
  ToLeft, // ◄ разрешение движения влево
  ToRight // ◄ разрешение движения вправо
} CanTetrominoMove_t;

/** @brief Соотвествие количества уничтоженных рядов и очков награды для счёта*/
typedef enum {
  OneLine = 100,    // ◄ 1 ряд → 100 очков
  TwoLines = 300,   // ◄ 2 ряда → 300 очков
  ThreeLines = 700, // ◄ 3 ряда → 700 очков
  FourLines = 1500  // ◄ 4 ряда → 1500 очков
} ErasedLinesScore_t;

/** @brief Фиксирование "соседей" пикселя*/
typedef struct {
  bool LBorder; // ◄ левая граница поля
  bool RBorder; // ◄ правая граница поля
  bool LBlock;  // ◄ блок слева (стат и двиг)
  bool RBlock;  // ◄ блок справа (стат и двиг)
} WhoIsNearby_t;

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

#endif