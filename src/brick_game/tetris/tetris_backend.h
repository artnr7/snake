#ifndef __TETRIS_BACKEND__
#define __TETRIS_BACEKND__

#include "tetris_include/tetris_backend_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

void userInput(UserAction_t action, bool hold);

GameInfo_t updateCurrentState();
#ifdef __cplusplus
}
#endif

#endif