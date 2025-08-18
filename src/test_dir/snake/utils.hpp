#ifndef UTILS_H_
#define UTILS_H_

#include "../../brick_game/data_types/data_types.h"

void MallocField(int ***field);

void GInfoInit(GameInfo_t &g_info);

void GInfoWrongInit(GameInfo_t &g_info);

bool EQGInfo(GameInfo_t &g_info_1, GameInfo_t &g_info_2);

bool EQEqual(bool &equal);

bool EQField(int **field_1, int **field_2);

int AreObjsInField(int px_code, int **field);

#endif