#include "../include/backend_utils.h"

#include <stdio.h>
#include <stdlib.h>

/** @brief Функция обработки действия игрока Start */
void init_game(GameInfo_t *g_info, int *tmino_pos) {
  if (is_nolaunched(g_info)) {
    g_info_init(g_info);
    bool init_fell = true; // ◄ одноразовая переменная, запускающая созд. тмино
    shall_create_tmino(g_info, &init_fell, tmino_pos);
    set_launched(g_info);
  }
  if (is_paused(g_info)) {
    set_launched(g_info);
  }
}

/** @brief Функции, выполняющиеся независимо от ввода игрока */
void gamestep(GameInfo_t *g_info, const UserAction_t *action, long int *dly,
              bool *tmino_fell, int *tmino_pos, bool *hold) {
  /* Если код выхода из игры или стоит пауза, выполняется выход, последующие
   * функции не выполняются*/
  if (is_inactive(g_info)) {
    return;
  }
  rand_fall(g_info, *action, dly, tmino_fell);
  rows_hit(g_info);
  shall_create_tmino(g_info, tmino_fell, tmino_pos);

  lvl_up(g_info);
  high_scr_set(g_info);

  dly_reset(*g_info, dly);
#ifdef TETRIS
  *hold += 1; // ◄ заглушка
#endif
}
