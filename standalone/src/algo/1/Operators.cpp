#include "Operators.h"

static const auto PLUS = Operator('+', 1);
static const auto MINUS = Operator('-', 1);
static const auto MULTIPLY = Operator('*', 2);
static const auto DEVIDE = Operator('/', 2);
static const auto BRACE_OPEN = Operator('(', 1);
static const auto BRACE_CLOSE = Operator(')', 3);

//const Operators::OperatorMap Operators::operatorMap = {
//    {PLUS.GetOperator(), PLUS},
//    {MINUS.GetOperator(), MINUS},
//    {MULTIPLY.GetOperator(), MULTIPLY},
//    {DEVIDE.GetOperator(), DEVIDE},
//    {BRACE_OPEN.GetOperator(), BRACE_OPEN},
//    {BRACE_CLOSE.GetOperator(), BRACE_CLOSE},
//};