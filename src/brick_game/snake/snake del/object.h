#ifndef OBJECT_H_
#define OBJECT_H_

#include "../../field_attr.h"
#include "../object_attr.h"

namespace s21 {

class Object {
public:
  void SetCords(cord_ref cord_y, cord_ref cord_x);

  virtual ~Object() = default;
};
} // namespace s21

#endif