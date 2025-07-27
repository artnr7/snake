#include "../include/object.h"

void s21::Object::SetCords(cord_ref cord_y, cord_ref cord_x) {
  cord_y_ = cord_y;
  cord_x_ = cord_x;
}

s21::Object::Object() : body_() {}

s21::Object::Object(const std::stack<ObjectPc> &body) : body_(body) {}