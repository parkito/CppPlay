
#include "ItalianPizza.h"

void ItalianPizza::cook() {
  std::cout << "Italian:";
  printComponents(*this);
}
