#include "Operator.h"

const Operator Operator::PLUS = Operator('+', 1);
const Operator Operator::MINUS = Operator('-', 1);
const Operator Operator::MULTIPLY = Operator('*', 2);
const Operator Operator::DEVIDE = Operator('/', 2);
const Operator Operator::BRACE_OPEN = Operator('(', 1);
const Operator Operator::BRACE_CLOSE = Operator(')', 3);
