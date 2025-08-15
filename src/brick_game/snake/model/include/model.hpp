#ifndef MODEL_H_
#define MODEL_H_

#include "../../../data_types/data_types.h"
#include "../snake_anim/snake_anim.hpp"

namespace s21 {

typedef enum { Nothing, Apple, Snake } PxCode;

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
  bool IsGameEnd();
  bool IsPaused();
  bool IsGameInactive();

  /*--------→ Score ←---------*/
  void IncreaseScore();

  /*--------→ Highscore ←---------*/
  void SetHighscore();
  int GetHighscore();

  /*--------→ Move ←---------*/
  bool MoveDelay();
  void MoveSnake(bool &dly);
  void RemoveOrNotTail(bool &ate_apple, bool &dly);

public:
  /*=====================→ METHODS ←==================== */
  static Model *GetModel();
  // не нужен void Mdealloc();

  GameInfo_t GetSInfo();
  /*--------→ Business ←---------*/
  void GameStep();

  void InitGame();
  void TakeBreak();
  void GoEnd();

  void SetSnakeDir(UserAction_t &action);
  void ChangeSpeed(bool &hold);
};
} // namespace s21

#endif