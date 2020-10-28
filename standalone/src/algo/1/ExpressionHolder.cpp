#include "ExpressionHolder.h"

void ExpressionHolder::AddValue(int value) { values.push_back(value); }

void ExpressionHolder::AddOperator(Operator op) { ops.push_back(op); }