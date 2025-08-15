#include "../include/model.hpp"
#include <chrono>
#include <iostream>

bool s21::Model::MoveDelay() {
  int move = 0;
  auto now = std::chrono::system_clock::now();
  auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
  auto value = ms.time_since_epoch();
  static long old_time = value.count();
  long new_time = value.count();

  static long time_diff = 0;
  time_diff += new_time - old_time;

  if (time_diff >= s_info_.speed) {
    move = 1;
    time_diff = 0;
  }

  old_time = value.count();

  return move;
}