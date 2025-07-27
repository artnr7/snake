#ifndef APPLE_H_
#define APPLE_H_

#include "object.h"
#include <iostream>

namespace s21 {

class Apple : public Object {

public:
  Apple();

  ObjectPc &GetBody();

private:
  ObjectPc apple_;
};
} // namespace s21

#endif