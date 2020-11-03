#include <iostream>
#include "Operators.h"

using namespace std;

int main() {
  //  ExpressionCalculator calc1 = ExpressionCalculator("(1+1)+(3*4)");
  //  cout << calc1.Calculate();

//  std::map<char, Operators> map = Operators::operatorMap;
  std::cout << Operators::PLUS.GetOperator();
  return 0;
}