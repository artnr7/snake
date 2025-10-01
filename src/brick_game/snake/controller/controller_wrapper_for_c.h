#ifndef CONTROLLER_WRAPPER_FOR_C_H_
#define CONTROLLER_WRAPPER_FOR_C_H_

#include "../../data_types/data_types.h"
#include "stdbool.h"

/** @brief Обёртка над Си++ для использования в Си-проектах */

#ifdef __cplusplus
extern "C" {
#endif

/** @brief Ввод игрока */
void userInput(UserAction_t action, bool hold);

/** @brief Получение переменных игры существующих в данный момент */
GameInfo_t updateCurrentState();

#ifdef __cplusplus
}
#endif

#endif