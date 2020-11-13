#include <iostream>

#include "Operator.h"

using namespace std;

int main() {
  //  ExpressionCalculator calc1 = ExpressionCalculator("(1+1)+(3*4)");
  //  cout << calc1.Calculate();

  //  std::map<char, Operators> map = Operators::operatorMap;
  Operator op = Operator::DEVIDE;
  std::cout << op.GetOperator();
  std::cout << op.GetPriority();
  //  cout << op.GetOperator();
  //  TestCls cls = TestCls();
  //  std::cout << cls.func();

  //  for (auto x : *Operator::operatorMap) {
  //    std::cout << x.first;
  //  }
  return 0;
}