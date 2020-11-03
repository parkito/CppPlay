#include <iostream>

#include "ExpressionCalculator.h"

using namespace std;

int main() {
  //  ExpressionCalculator calc1 = ExpressionCalculator("(1+1)+(3*4)");
  //  cout << calc1.Calculate();

  std::map<char, Operators> map = Operators::operatorMap;
  std::cout << " ";
  return 0;
}