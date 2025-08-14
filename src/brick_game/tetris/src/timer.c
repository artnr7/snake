#include "../include/timer.h"

/** @brief Получение и фиксирование задержки для функции падения тетромино
 * @details Сравниваем "старое" время и "новое", до и после проведения основного
 * игрового цикла соответственно и записываем(прибавляем) его в dly, после
 * "накопления" задержки срабатывает функция падения тетромино(tetromino_fall)
 * @param dly задержка
 */
void dly_get(long int *dly) {
  static struct timeval old_time;
  struct timeval new_time;

  static int i = 0;
  if (i++ == 0) {
    gettimeofday(&old_time, NULL);
  }

  gettimeofday(&new_time, NULL);
  /* Переводим секунды в более точные миллисекунды, очень вряд ли когда-либо
  будет больше 0
  ▼ */
  long microsec = (new_time.tv_sec - old_time.tv_sec) * MICROSEC_IN_SEC;
  /* ▼ Переводим микросекунды в менее точные миллисекунды */
  long usec = microsec + new_time.tv_usec - old_time.tv_usec;

  /* ▼ "Копим" задержку */
  *dly += usec;

  gettimeofday(&old_time, NULL);
}

/** @brief Сброс задержки для функции падения тетромино
 * @details После того как задержка "накопилась" и функция падения тетромино
 * отработала, мы сбрасываем её, чтобы заново копить
 * @param dly задержка
 */
void dly_reset(GameInfo_t g_info, long int *dly) {
  if (*dly > g_info.speed) {
    *dly = 0;
  }
}