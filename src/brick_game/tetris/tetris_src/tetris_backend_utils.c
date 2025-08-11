#include "../tetris_include/tetris_backend_utils.h"

#include <stdlib.h>

/** @brief Реакция на действия пользователя */
void act_fncs(GameInfo_t *tg_info, UserAction_t action, long int dly,
              bool *tmino_fell, int *tmino_pos) {
  switch (action) {
    case Start:
      start_fn(tg_info, tmino_pos);
      break;
    case Pause:
      tg_info->pause = 1;  // ◄ pause == 1 - пауза игры
      break;
    case Terminate:
      tg_info_and_nxt_frm_free(tg_info);
      break;
    case Left:
      lr_mv(tg_info, Left);
      break;
    case Right:
      lr_mv(tg_info, Right);
      break;
    case Down:
      action_down_fn(tg_info, tmino_fell);
      break;
    case Action:
      action_fn(tg_info, tmino_pos, tmino_fell);
      break;
    default:
      tmino_fall_with_dly(tg_info, tmino_fell, dly);
  }
}

/** @brief Функция обработки действия игрока Start
 * @details Изначально в pause лежит мусор, чтобы как-то его обработать, идём от
 * обратного и проверяем !=2, это верно, поэтому поле инициализируется
 * При последующих вводах, благодаря тому что в любом случае во втором блоке if
 * будет false, потому что pause при вызове этой функции всегда будет 2
 */
void start_fn(GameInfo_t *tg_info, int *tmino_pos) {
  if (tg_info->pause == 1) {
    /* pause == 2 это состояние игры без паузы, но не самое первое состояние при
      старте, сделано это для того чтобы после снятия паузы не пересоздавалось
      поле
      ▼ */
    tg_info->pause = 2;
  }
  /* Здесь сравнение на отрицание идёт потому что при запуске программы,
   переменная pause не определена
   ▼ */
  if (tg_info->pause != 2) {
    tg_info_init(tg_info);

    bool init_fell = true;  // ◄ одноразовая переменная, запускающая созд. тмино
    shall_create_tmino(tg_info, &init_fell, tmino_pos);
    tg_info->pause = 2;
  }
}

/** @brief Функции, выполняющиеся независимо от ввода игрока */
void noact_fncs(GameInfo_t *tg_info, const UserAction_t *action, long int *dly,
                bool *tmino_fell, int *tmino_pos, bool *hold) {
  /* Если код выхода из игры или стоит пауза, выполняется выход, последующие
   * функции не выполняются*/
  if (tg_info->field == NULL || *action == Terminate || tg_info->pause == 1 ||
      !(malloc_check(tg_info))) {
    return;
  }

  rand_fall(tg_info, *action, *dly, tmino_fell);
  rows_hit(tg_info);
  shall_create_tmino(tg_info, tmino_fell, tmino_pos);

  lvl_up(tg_info);
  high_scr_set(tg_info);

  dly_reset(*tg_info, dly);
  *hold += 1;  // ◄ заглушка
}
