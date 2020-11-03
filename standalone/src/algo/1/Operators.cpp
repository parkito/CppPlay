#include "Operators.h"

static const auto PLUS =  Operator('+', 1);
static const auto MINUS = Operator('-', 1);
static const auto MULTIPLY = Operator('*', 2);
static const auto DEVIDE = Operator('/', 2);
static const auto BRACE_OPEN = Operator('(', 1);
static const  auto BRACE_CLOSE = Operator(')', 3);

const Operators::OperatorMap Operators::operatorMap =  {
      {PLUS.GetOperator(), Operators::PLUS},
      {MINUS.GetOperator(), Operators::MINUS},
      {MULTIPLY.GetOperator(), Operators::MULTIPLY},
      {DEVIDE.GetOperator(), Operators::DEVIDE},
      {BRACE_OPEN.GetOperator(), Operators::BRACE_OPEN},
      {BRACE_CLOSE.GetOperator(), Operators::BRACE_CLOSE},
};