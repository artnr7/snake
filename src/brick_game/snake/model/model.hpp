#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "../../data_types/data_types.h"
#include "snake_anim/snake_anim.hpp"

namespace s21 {

class Model {
 protected:
  Model();

  static Model *model_;
  /*=====================→ VARIABLES ←==================== */
  GameInfo_t s_info_;
  ObjectPc apple_;
  SnakeAnim snake_anim_;

  /*=====================→ METHODS ←==================== */
  void Malloc();

  /*-------------------→ UTILS ←----------------------*/
  void ClearField();
  void WalkOnSnake(PxCode &px_code);

  /*--------→ Parse ←---------*/
  void ParseObjs();
  void ParseSnake();
  void ParseApple();

  /*-------------------→ APPLE ←----------------------*/
  void SpawnApple();
  int EatApple();

  /*-------------------→ SNAKE ←----------------------*/

  /*--------→ Speed ←---------*/
  void SetSnakeSpeed();
  void GetAccSpeed();
  void GetConstSnakeSpeed();

  /*--------→ Levels ←---------*/
  void LevelUp();

  /*--------→ Collision ←---------*/
  void Collision();
  void WallCollision();
  void SnakeSelfCollision();

  /*--------→ GameState Check ←---------*/
  bool IsLaunched();
  bool IsNoLaunched();
  bool IsLanchedOrPaused();
  bool IsGameoveredOrTerminated();
  bool IsWoned();
  bool IsGameEnd();
  bool IsPaused();

  /*--------→ Score ←---------*/
  void IncreaseScore();

  /*--------→ Highscore ←---------*/
  void SetHighscore();
  int GetHighscore();

  /*--------→ Move ←---------*/
  bool MoveDelay();
  void MoveSnake(bool &dly);
  void RemoveOrNotTail(bool &ate_apple, bool &dly);

  /*--------→ Win ←---------*/
  void Win();

 public:
  /*=====================→ METHODS ←==================== */
  /** @brief Геттер синглтона модели */
  static Model *GetModel();

  /** @brief Геттер структуры переменных игры существующих в данный момент */
  GameInfo_t GetSInfo();

  /*--------→ Business ←---------*/
  /** @brief Шаг игры
   * @details Сборник функций выполняющихся при каждом вызове обновления
   * контроллера
   */
  void GameStep();

  /** @brief Инициализация игры */
  void InitGame();

  /** @brief Постановка игры на паузу */
  void TakeBreak();

  /** @brief Команда завершить игру и установить соответствующее состояние */
  void GoEnd();

  /** @brief Установка направления движения змейки в соответствии данной команде
   * контроллеру */
  void SetSnakeDir(UserAction_t &action);

  /** @brief Установка скорости в зависимости от переменной данной контроллеру*/
  void ChangeSpeed(bool &hold);
};
}  // namespace s21

#endif

/** @mainpage
 * Проект Brick Game v2.0
 */