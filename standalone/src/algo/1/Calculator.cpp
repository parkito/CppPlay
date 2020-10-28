#include <iostream>

#include "ExpressionCalculator.h"

using namespace std;
int main() {
  ExpressionCalculator calc1 = ExpressionCalculator("1+1");

  cout << calc1.calculate();
  return 0;
}