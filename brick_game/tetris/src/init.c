#include "../include/init.h"

/** @brief Объявление статического объекта игровой структуры */
GameInfo_t *get_g_info() {
  static GameInfo_t g_info;
  static int i = 0;
  if (i++ == 0) {
    g_info.pause = NoLaunched;
  }
  if (is_nolaunched(&g_info)) {
    fld_malloc_and_fill(&(g_info.field), FIELD_H, FIELD_W);
    fld_malloc_and_fill(&(g_info.next), NEXT_TMINO_H, NEXT_TMINO_W);
  }
  return &g_info;
}

/** @brief Инициализация статического объекта следующего кадра игрового поля */
int **fld_nxt_frm(int mode) {
  static int **nxt_frm;
  static int i = 0;
  if (i++ == 0) {
    fld_malloc_and_fill(&nxt_frm, FIELD_H, FIELD_W);
  }
  if (mode == 1 && nxt_frm != NULL) {
    free(nxt_frm);
    nxt_frm = NULL;
  }

  return nxt_frm;
}

/** @brief Инициализация статического объекта игровой структуры */
void g_info_init(GameInfo_t *g_info) {
  g_info->level = 0;
  g_info->score = 0;
  g_info->speed = 0;
  high_scr_get(g_info);
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
bool malloc_check(GameInfo_t *g_info) {
  bool ptrs_nonnull = true;
  int **nxt_frm = fld_nxt_frm(0);

  if (g_info->field == NULL || g_info->next == NULL || nxt_frm == NULL) {
    g_info_and_nxt_frm_free(g_info);
    ptrs_nonnull = false;
  }
  return ptrs_nonnull;
}

/** @brief Освободждене памяти игровых полей */
void g_info_and_nxt_frm_free(GameInfo_t *g_info) {
  fld_nxt_frm(1);
  if (g_info->field != NULL) {
    free(g_info->field);
    g_info->field = NULL;
  }
  if (g_info->next != NULL) {
    free(g_info->next);
    g_info->next = NULL;
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

void go_end(GameInfo_t *g_info) {
  g_info_and_nxt_frm_free(g_info);
  set_terminated(g_info);
}