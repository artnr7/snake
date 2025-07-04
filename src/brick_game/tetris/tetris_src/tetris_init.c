#include "../tetris_include/tetris_init.h"

/** @brief Объявление статического объекта игровой структуры */
GameInfo_t *tg_info_stc_obj() {
  static GameInfo_t tg_info;
  return &tg_info;
}

/** @brief Инициализация статического объекта следующего кадра игрового поля */
int **fld_nxt_frm(int mode) {
  static int **nxt_frm;
  static int i = 0;
  if (i++ == 0) {
    fld_malloc_and_fill(&nxt_frm, FLD_H, FLD_W);
  }
  if (mode == 1 && nxt_frm != NULL) {
    free(nxt_frm);
    nxt_frm = NULL;
  }

  return nxt_frm;
}

/** @brief Инициализация статического объекта игровой структуры */
void tg_info_init(GameInfo_t *tg_info) {
  fld_malloc_and_fill(&(tg_info->field), FLD_H, FLD_W);
  fld_malloc_and_fill(&(tg_info->next), NEXT_TMINO_H, NEXT_TMINO_W);

  tg_info->high_score = 0;
  tg_info->pause = 0;
  tg_info->level = 0;
  tg_info->score = 0;
  tg_info->speed = 0;

  high_scr_get(tg_info);
}

/** @brief Выделение памяти для игровых полей */
void fld_malloc_and_fill(int ***field, int H, int W) {
  *field = (int **)malloc(sizeof(int *) * H + sizeof(int) * H * W);
  if (*field != NULL) {
    int *ptr = (int *)(*field + H);
    for (int i = 0; i < H; i++) {
      (*field)[i] = ptr + W * i;
      for (int j = 0; j < W; j++) {
        (*field)[i][j] = Nothing;
      }
    }
  }
}

/** @brief Проверка на выделение памяти */
bool malloc_check(GameInfo_t *tg_info) {
  bool ptrs_nonnull = true;
  int **nxt_frm = fld_nxt_frm(0);

  if (tg_info->field == NULL || tg_info->next == NULL || nxt_frm == NULL) {
    tg_info_and_nxt_frm_free(tg_info);
    ptrs_nonnull = false;
  }
  return ptrs_nonnull;
}

/** @brief Освободждене памяти игровых полей */
void tg_info_and_nxt_frm_free(GameInfo_t *tg_info) {
  fld_nxt_frm(1);
  if (tg_info->field != NULL) {
    free(tg_info->field);
    tg_info->field = NULL;
  }
  if (tg_info->next != NULL) {
    free(tg_info->next);
    tg_info->next = NULL;
  }
}

/** @brief Инициализация Tetromino_t */
Tetromino_t *tminos_init() {
  static Tetromino_t tminos[] = {

      /* ▼ I-тетромино */
      {.shape = L"■■■■", .px_code = RedIMvg},

      /* ▼ L-тетромино */
      {.shape =

           L"**■\
             ■■■",
       .px_code = GreenLMvg},

      /* ▼ Z-тетромино */
      {.shape =

           L"■■*\
             *■■",
       .px_code = YellowZMvg},

      /* ▼ J-тетромино */
      {.shape =

           L"■**\
             ■■■",
       .px_code = BlueJMvg},

      /* ▼ O-тетромино */
      {.shape =

           L"■■\
             ■■",
       .px_code = MagentaOMvg},

      /* ▼ S-тетромино */
      {.shape =

           L"*■■\
             ■■*",
       .px_code = CyanSMvg},

      /* ▼ T-тетромино */
      {.shape =

           L"*■*\
             ■■■",
       .px_code = WhiteTMvg}};

  return tminos;
}