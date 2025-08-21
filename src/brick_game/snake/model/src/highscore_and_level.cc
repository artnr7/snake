#include <fstream>
#include <iostream>

#include "../model.hpp"

#define PointsToLevelUp 5
#define MaxLevelsNum 10

void s21::Model::LevelUp() {
  s_info_.level = s_info_.score / PointsToLevelUp <= 10
                      ? s_info_.score / PointsToLevelUp
                      : s_info_.level;
}

void s21::Model::SetHighscore() {
  if (s_info_.score > s_info_.high_score) {
    s_info_.high_score = s_info_.score;
    std::cout << "fdsf";
    std::ofstream fout("../brick_game/snake/data_base/highscore.txt");
    if (fout.is_open()) {
      fout << s_info_.high_score;
      fout.close();
    }
  }
}

int s21::Model::GetHighscore() {
  int highscore = 0;
  std::ifstream fin("../brick_game/snake/data_base/highscore.txt");
  if (fin.is_open()) {
    fin >> highscore;
    fin.close();
  }
  return highscore;
}