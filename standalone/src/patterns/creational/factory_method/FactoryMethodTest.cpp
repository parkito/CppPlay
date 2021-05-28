#include "AbstractPizza.h"

int main() {
  auto pizza1 = PizzaFactory::prepare(Size::big, PizzaType::norishing);
  pizza1->cook();
}