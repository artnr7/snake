#include "tetris_backend.h"

void userInput(UserAction_t action, bool hold) {
  GameInfo_t *tg_info = tg_info_stc_obj();
  static bool tmino_fell = false;  // ◄
  static int tmino_pos = 0;
  static long int dly = 0;
  srand(clock());

  dly_get(&dly);
  act_fncs(tg_info, action, dly, &tmino_fell, &tmino_pos);
  noact_fncs(tg_info, &action, &dly, &tmino_fell, &tmino_pos, &hold);
}

GameInfo_t updateCurrentState() { return *(tg_info_stc_obj()); }
