#include "Operator.h"

char Operator::GetOperator() const { return sym; }

int Operator::GetPriority() const { return priority; }
