#include "../include/model.h"

/** @brief  */

s21::Model *s21::Model::model_ = nullptr;
// s21::Model::model_ = nullptr;

s21::Model *s21::Model::GetModel() {

  if (model_ == nullptr) {
    model_ = new Model();
  }
  return model_;
}

s21::Model::Model() : s_info_() { Malloc(); }

void s21::Model::Malloc() {
  if (!s_info_.field) {
    s_info_.field = new int *[FIELD_H] {};

    for (int i = 0; i < FIELD_H; ++i) {
      (s_info_.field)[i] = new int[FIELD_W]{};
    }
  }
}

// не нужен
// void s21::Model::Mdealloc() {
//   if (s_info_.field != nullptr) {
//     for (int i = 0; i < FIELD_H; ++i) {
//       delete[] (s_info_.field)[i];
//     }
//     delete[] s_info_.field;
//   }
// }

/*=====================→ BUSINESS ←==================== */
