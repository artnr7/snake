#ifndef __TETRIS_BACKEND__
#define __TETRIS_BACKEND__

#include "include/backend_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

void userInput(UserAction_t action, bool hold);

GameInfo_t updateCurrentState();
#ifdef __cplusplus
}
#endif

#endif