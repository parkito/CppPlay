#pragma once

#include <utility>

#include "ExpressionHolder.h"
#include "string"

class ExpressionCalculator {
public:
  explicit ExpressionCalculator(std::string& expression) : expression(expression) {}
  double Calculate();

private:
  std::string expression;
  ExpressionHolder ToHolder(std::string& expression);
};
