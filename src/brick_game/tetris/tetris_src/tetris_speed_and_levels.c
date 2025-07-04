#include "../tetris_include/tetris_speed_and_levels.h"

/** @brief Повышение уровня игры */
void lvl_up(GameInfo_t *tg_info) {
  tg_info->level = (tg_info->score / 600) + 1;
  /* ▼ Ограничение уровня */
  tg_info->level = tg_info->level <= LVL_QTY ? tg_info->level : LVL_QTY;
  tg_info->speed = ((LVL_QTY + 1) - tg_info->level) * SPD_MLT;
}

/** @brief Получение рекорда из файла */
void high_scr_get(GameInfo_t *tg_info) {
  tg_info->high_score = 0;
  const char *high_scr_file = "brick_game/tetris/high_score.txt";
  FILE *fp = fopen(high_scr_file, "r");
  if (!fp) {  // ◄ если файла не существует - создаём
    fp = fopen(high_scr_file, "w");
    if (fp) {
      fclose(fp);
    }
  } else {
    char highscr_str[11] = "tensymbols";
    fgets(highscr_str, 10, fp);  //
    tg_info->high_score = atoi(highscr_str);
    fclose(fp);
  }
}

/** @brief Запись рекорда в файл */
void high_scr_set(GameInfo_t *tg_info) {
  if (tg_info->score > tg_info->high_score) {
    tg_info->high_score = tg_info->score;
    const char *high_scr_file = "brick_game/tetris/high_score.txt";
    FILE *fp = fopen(high_scr_file, "w");

    if (fp) {
      char highscr_str[11];
      snprintf(highscr_str, 10, "%d", tg_info->score);
      const char *highscr_str_ptr = highscr_str;
      fputs(highscr_str_ptr, fp);
      fclose(fp);
    }
  }
}
