#ifndef OBJECT_H_
#define OBJECT_H_

#include "config.h"

namespace s21 {

using cord = int;
using cord_ref = int &;

typedef struct {
  cord cord_y_ = 0;
  cord cord_x_ = 0;
} ObjectPc;

class Object {
public:
  void SetCords(cord_ref cord_y, cord_ref cord_x);

  virtual ~Object() = default;
};
} // namespace s21

#endif