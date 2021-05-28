#pragma once

#include "AbstractPizza.h"

class PizzaShop {
public:
  static AbstractPizza prepare(Size size, PizzaType type);
};
