#ifndef OBJECT_ATTR_
#define OBJECT_ATTR_

namespace s21 {
using cord = int;

typedef struct {
  cord cord_y_ = 0;
  cord cord_x_ = 0;
} ObjectPc;

typedef enum { Nothing, Apple, Snake } PxCode;

typedef enum { Up, Right, Down, Left } SnakeDirection;

} // namespace s21
#endif