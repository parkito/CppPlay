#include "ExpressionHolder.h"

void ExpressionHolder::AddValue(int value) { values.push_back(value); }

void ExpressionHolder::AddOperator(Operators op) { ops.push_back(op); }