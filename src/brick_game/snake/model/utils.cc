#include "model.h"

void s21::Model::ParseObj() {
    s_info_.field[apple_.GetBody().cord_y_][apple_.GetBody().cord_x_] =
        PxCode::Apple;
        
  auto it_b = (snake_anim_.GetBody()).begin();
  auto it_e = (snake_anim_.GetBody()).end();
  for (auto it_b = (snake_anim_.GetBody()).begin(); it_b != it_e; ++it_b) {
    (s_info_.field)[(*it_b).cord_y_][(*it_b).cord_x_] = PxCode::Snake;
  }

}