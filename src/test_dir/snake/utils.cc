#include "utils.hpp"

#include <iostream>

void MallocField(int ***field) {
  *field = new int *[FIELD_H] {};

  for (int i = 0; i < FIELD_H; ++i) {
    (*field)[i] = new int[FIELD_W]{};
  }
}

void GInfoInit(GameInfo_t &g_info) {
  MallocField(&g_info.field);
  g_info.next = nullptr;
  g_info.level = 0;
  g_info.pause = GameState::NoLaunched;
  g_info.score = 0;
}

void GInfoWrongInit(GameInfo_t &g_info) {
  g_info.field = nullptr;
  g_info.next = nullptr;
  g_info.level = 1000;
  g_info.pause = GameState::Terminated;
  g_info.score = 4233;
}

bool EQGInfo(GameInfo_t &g_info_1, GameInfo_t &g_info_2) {
  bool equal = true;

  equal = EQField(g_info_1.field, g_info_2.field);
  equal = g_info_1.level == g_info_2.level ? EQEqual(equal) : false;
  equal = g_info_1.next == g_info_2.next ? EQEqual(equal) : false;
  equal = g_info_1.pause == g_info_2.pause ? EQEqual(equal) : false;
  equal = g_info_1.score == g_info_2.score ? EQEqual(equal) : false;

  return equal;
}

bool EQEqual(bool &equal) { return equal == false ? false : true; }

bool EQField(int **field_1, int **field_2) {
  bool equal = true;
  if (field_1 != nullptr && field_2 != nullptr) {
    for (int i = 0; i < FIELD_H && equal; ++i) {
      for (int j = 0; j < FIELD_W && equal; ++j) {
        if (field_1[i][j] != field_2[i][j]) {
          equal = false;
        }
      }
    }
  }

  if (field_1 == nullptr || field_2 == nullptr) {
    equal = field_1 == field_2 ? true : false;
  }

  return equal;
}

int AreObjsInField(int px_code, int **field) {
  int count = 0;

  for (int i = 0; i < FIELD_H; ++i) {
    for (int j = 0; j < FIELD_W; ++j) {
      if (field[i][j] == px_code) {
        ++count;
      }
    }
  }
  return count;
}