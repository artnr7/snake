#include "../include/model.h"

#define PointsToLevelUp 5
#define MaxLevelsNum 10

void s21::Model::LevelUp() {
  s_info_.level = s_info_.score / PointsToLevelUp <= 10
                      ? s_info_.score / PointsToLevelUp
                      : s_info_.level;
}