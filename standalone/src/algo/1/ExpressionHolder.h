#pragma once
#include <string>
#include <vector>

#include "Operator.h"

class ExpressionHolder {
public:
  void AddValue(int value);
  void AddOperator(Operator op);

private:
  std::vector<int> values;
  std::vector<Operator> ops;
};
