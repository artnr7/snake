#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "../../data_types/data_types.h"
#include "snake_anim/snake_anim.hpp"

#define MAX_SCORE (FIELD_H * FIELD_W)
/** @brief Значения клеток поля */
typedef enum { NothingSnake, Apple, Snake } PxCode;

namespace s21 {
class Model {
 protected:
  Model();

  static Model *model_;
  /*=====================→ VARIABLES ←==================== */
  GameInfo_t s_info_;
  ObjectPc apple_;
  SnakeAnim snake_anim_;
  static bool skip_buffer_further_;
  static UserAction_t buffer_;

  /*=====================→ METHODS ←==================== */
  /** @brief Выделение памяти для игрового поля */
  void Malloc();

  /*-------------------→ UTILS ←----------------------*/
  /** @brief Очищение поля для последующего парсинга */
  void ClearField();
  /** @brief Проходится в поле по кордам змейки и ставит соответствующий код в
   * ячейку поля */
  void WalkOnSnake(PxCode &px_code);

  /*--------→ Parse ←---------*/
  void ParseObjs();
  /** @brief Парсинг змейки в поле */
  void ParseSnake();
  /** @brief Парсинг яблока в поле */
  void ParseApple();

  /*-------------------→ APPLE ←----------------------*/
  /** @brief Спавн яблока в случайной свободной ячейке поля
   * @todo Когда больше не будет свободной ячейки игра должна завершаться */
  void SpawnApple();
  /** @brief Проверка ест ли змейка яблоко */
  int EatApple();

  /*-------------------→ SNAKE ←----------------------*/

  /*--------→ Speed ←---------*/
  /** @brief Установление новой скорости при увеличении уровня */
  void SetSnakeSpeed();
  /** @brief Получение скорости при ускорении */
  void GetAccSpeed();
  /** @brief Получение скорости без ускорения */
  void GetConstSnakeSpeed();

  /*--------→ Levels ←---------*/
  /** @brief Увеличение уровня */
  void LevelUp();

  /*--------→ Collision ←---------*/
  /** @brief Коллизия со стенами и змейки с самой собой */
  void Collision();
  /** @brief Коллизия со стеной */
  void WallCollision();
  /** @brief Коллизия змейки с самой собой */
  void SnakeSelfCollision();

  /*--------→ GameState Check ←---------*/
  /** @brief Находится ли игра в состянии Запущенном */
  bool IsLaunched();
  /** @brief Находится ли игра в состянии Незапущенная */
  bool IsNoLaunched();
  /** @brief Находится ли игра в состянии Паузы */
  bool IsPaused();

  /*--------→ Score ←---------*/
  /** @brief Увеличение счёта */
  void IncreaseScore();

  /*--------→ Highscore ←---------*/
  /** @brief Установление нового значения рекорда */
  void SetHighscore();
  /** @brief Получение старого рекорда */
  int GetHighscore();

  /*--------→ Move ←---------*/
  /** @brief Решение что делать с задержкой движения
   * @details Исходя из того сколько времени прошло принмается решение
   * сбрасывать таймер и позволять змейке двигаться */
  bool MoveDelay();
  /** @brief Движение змейки если задержка позволяет */
  void MoveSnake(bool &dly);
  /** @brief Решение убирать ли хвост у змейки в этом кадре */
  void RemoveOrNotTail(bool &ate_apple, bool &dly);

  /*--------→ Win ←---------*/
  /** @brief Установление статуса игры как Выигранная */
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
  void SetSnakeDir();

  /** @brief Установка скорости в зависимости от переменной данной контроллеру*/
  void ChangeSpeed(bool &hold);
};
}  // namespace s21

#endif

/** @mainpage
 * Проект Brick Game v2.0
 */