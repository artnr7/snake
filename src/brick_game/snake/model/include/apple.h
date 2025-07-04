#ifndef APPLE_H_
#define APPLE_H_

#include "object.h"
#include <random>


namespace s21 {

class Apple : public Object {

public:
  Apple();

private:
  ObjectPc apple_;
}
} // namespace s21

#endif