#include "../tetris_include/tetris_tetromino_create.h"

/** @brief Следует ли создавать тетромино
 * @details Исходя из входных данных принимается решение следует ли создавать
 * тетромино на игровом поле
 */
void shall_create_tmino(GameInfo_t *tg_info, bool *tmino_fell, int *tmino_pos) {
  if (!malloc_check(tg_info)) {
    return;
  }
  Tetromino_t *tmino = tmino_stc_obj();

  /* Если фигура упала, то вызывается новая фигура, и статус
   * падения меняется на ложный
   ▼ */
  if (can_create_tmino_fn(tg_info, *tmino) && *tmino_fell == true) {
    fld_tmino_create(tg_info, tmino, tmino_pos);
    *tmino_fell = false;
  }
}

/** @brief Создание статического объекта структуры тетромино */
Tetromino_t *tmino_stc_obj() {
  static Tetromino_t tmino;
  static int i = 0;
  if (i++ == 0) {
    get_tmino(&tmino);
  }

  return &tmino;
}

/** @brief Создание нового тетромино на игровом поле
 * @details Сначала проходит инициализация позиции 0, парсинг шаблона на игровое
 * поле
 */
void fld_tmino_create(GameInfo_t *tg_info, Tetromino_t *tmino, int *tmino_pos) {
  *tmino_pos = 0;  // ◄ инициализация позиции нового тетромино, всегда 0
  tmino_parser(tg_info->field, *tmino, TMINO_START_Y, TMINO_START_X, 0);

  get_tmino(tmino);
  for (int i = 0; i < NEXT_TMINO_H; i++) {
    for (int j = 0; j < NEXT_TMINO_W; j++) {
      tg_info->next[i][j] = Nothing;
    }
  }
  tmino_parser(tg_info->next, *tmino, 0, 0, 0);
}

/** @brief Получение тетромино в структуру */
void get_tmino(Tetromino_t *tmino) {
  srand(clock());
  int tmino_rand_id = rand() % TMINO_QTY;  // ◄ случайный выбор из 7 вариантов
  tmino->shape = (*(tminos_init() + tmino_rand_id)).shape;
  tmino->px_code = (*(tminos_init() + tmino_rand_id)).px_code;
}

/** @brief Проверка может ли создасться тетромино
 * @details Если создать не можем значит игра закончена, следовательно игра
 * завершается поэтому далее чистим память
 */
bool can_create_tmino_fn(GameInfo_t *tg_info, const Tetromino_t tmino) {
  /* ▼ Проверка может ли создасться тетромино */
  bool can_create_tmino = true;
  if (!tmino_parser(tg_info->field, tmino, TMINO_START_Y, TMINO_START_X, 1)) {
    tg_info_and_nxt_frm_free(tg_info);
    can_create_tmino = false;
  }
  return can_create_tmino;
}

/** @brief Парсер тетромино
 * @param mode 0 ◄ из переданного в него шаблона в игровое поле рисуется
 * тетромино, по заданным координатам записывается код блоков
 * @param mode 1 ◄ по переданному в функцию шаблона проверяется заняты ли
 * блоки в поле, исходя из этого узнаём есть ли возможность создать тетромино
 */
bool tmino_parser(int **field, const Tetromino_t tmino, int st_y, int st_x,
                  int mode) {
  wchar_t ch = L'♥';
  int str_i = 0, y = st_y, x = st_x;
  bool spc_skip = false, can_tmino_create = true;

  while (ch != '\0') {
    ch = tmino.shape[str_i++];
    /* Когда мы видим первый пробел, то прибавляем координату по y, и не
     * прибавляем до тех пор пока пробелы не закончатся и будет какой-нибудь
     * другой символ
     * ▼ */
    if (ch == ' ') {
      if (spc_skip == false) {
        y++;
        x = st_x;
        spc_skip = true;
      }
      continue;
    }
    spc_skip = false;
    /* ▼ Eсли попадается знак тетромино */
    if (ch == L'■') {  // ■
      /* ▼ Записываем в поле код тетромино */
      if (mode == 0) {
        field[y][x] = tmino.px_code;
      }

      /* ▼ Если блок занят, то создать фигуру не можем  */
      if (mode == 1 && stc_px_dtrm(field[y][x])) {
        can_tmino_create = false;
      }
    }
    /* Координату x прибавляем всегда, если там будет знак тетромино понятно,
      потому что эту точку мы уже отметили, однако если там будет "*", нам всё
      равно нужно сдвигать координату, потому что в моей системе знак точки
      означает отсутствие знака тетромино ▼ */
    x++;
  }
  return can_tmino_create;
}
