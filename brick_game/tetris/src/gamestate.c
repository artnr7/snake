#include "../include/gamestate.h"

bool is_nolaunched(GameInfo_t *g_info) { return g_info->pause == NoLaunched; }
bool is_launched(GameInfo_t *g_info) { return g_info->pause == Launched; }
bool is_paused(GameInfo_t *g_info) { return g_info->pause == Paused; }

bool is_launched_or_paused(GameInfo_t *g_info) {
  return is_launched(g_info) || is_paused(g_info);
}
bool is_gameovered_or_terminated(GameInfo_t *g_info) {
  return g_info->pause == GameOvered || g_info->pause == Terminated;
}
bool is_game_end(GameInfo_t *g_info) {
  return is_gameovered_or_terminated(g_info);
}
bool is_inactive(GameInfo_t *g_info) {
  return is_nolaunched(g_info) || is_paused(g_info) || is_game_end(g_info);
}

void set_launched(GameInfo_t *g_info) { g_info->pause = Launched; }
void set_paused(GameInfo_t *g_info) { g_info->pause = Paused; }
void set_terminated(GameInfo_t *g_info) { g_info->pause = Terminated; }