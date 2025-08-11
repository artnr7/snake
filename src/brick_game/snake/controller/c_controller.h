#include "../data_types.h"
#include "stdbool.h"

#ifdef __cplusplus
extern "C" {
#endif

void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();

#ifdef __cplusplus
}
#endif