#pragma once
#include <string>
#include <vector>

#include "Operators.h"

class ExpressionHolder {
public:
  void AddValue(int value);
  void AddOperator(Operators op);

private:
  std::vector<int> values;
  std::vector<Operators> ops;
};
