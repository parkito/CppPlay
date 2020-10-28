#pragma once

#include "ExpressionHolder.h"
#include "string"

class ExpressionCalculator {
public:
  ExpressionCalculator(const std::string& expression) : expression(expression) {}
  double calculate();

private:
  std::string expression;
};
