#include "backend.h"

void userInput(UserAction_t action, bool hold) {
  GameInfo_t *g_info = get_g_info();
  static bool tmino_fell = false;
  static int tmino_pos = 0;
  static long int dly = 0;
  srand(clock());

  dly_get(&dly);

  switch (action) {
    case Start:
      init_game(g_info, &tmino_pos);
      break;
    case Pause:
      set_paused(g_info);
      break;
    case Terminate:
      go_end(g_info);
      break;
    case Left:
      lr_mv(g_info, Left);
      break;
    case Right:
      lr_mv(g_info, Right);
      break;
    case Down:
      tmino_drop(g_info, &tmino_fell);
      break;
    case Action:
      tmino_spin(g_info, &tmino_pos, &tmino_fell);
      break;
    default:
      break;
  }

  gamestep(g_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
}

GameInfo_t updateCurrentState() { return *(get_g_info()); }
