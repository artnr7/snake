#include "../model.hpp"
#define DEFAULT_SNAKE_SPEED DEFAULT_SPEED
#define SNAKE_SPEED_MULT 20

/** @brief Установка скорости в зависимости от переменной данной контроллеру */
void s21::Model::ChangeSpeed(bool &hold) {
  if (hold) {
    GetAccSpeed();
  } else {
    GetConstSnakeSpeed();
  }
}

/** @brief Получение скорости при ускорении */
void s21::Model::GetAccSpeed() { s_info_.speed = snake_anim_.GetAccSpeed(); }

/** @brief Получение скорости без ускорения */
void s21::Model::GetConstSnakeSpeed() {
  s_info_.speed = snake_anim_.GetConstSpeed();
}

/** @brief Установление новой скорости при увеличении уровня */
void s21::Model::SetSnakeSpeed() {
  snake_anim_.GetSpeed() =
      DEFAULT_SNAKE_SPEED - s_info_.level * SNAKE_SPEED_MULT;
}
