#ifndef __GAMESTATE__
#define __GAMESTATE__

#include <stdbool.h>

#include "../../data_types/data_types.h"

bool is_nolaunched(GameInfo_t *g_info);
bool is_launched(GameInfo_t *g_info);
bool is_paused(GameInfo_t *g_info);
bool is_launched_or_paused(GameInfo_t *g_info);
bool is_gameovered_or_terminated(GameInfo_t *g_info);
bool is_game_end(GameInfo_t *g_info);
bool is_inactive(GameInfo_t *g_info);

void set_launched(GameInfo_t *g_info);
void set_paused(GameInfo_t *g_info);
void set_terminated(GameInfo_t *g_info);
#endif