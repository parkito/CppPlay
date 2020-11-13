#include "Operator.h"

const Operator Operator::PLUS = Operator('+', 1);
const Operator Operator::MINUS = Operator('-', 1);
const Operator Operator::MULTIPLY = Operator('*', 2);
const Operator Operator::DEVIDE = Operator('/', 2);
const Operator Operator::BRACE_OPEN = Operator('(', 1);
const Operator Operator::BRACE_CLOSE = Operator(')', 3);

Operator::Operator(char sym, int priority) : sym(sym), priority(priority) {
//  static std::map<char, Operator> tempMap;
//  tempMap.insert(std::pair(PLUS.sym, PLUS));
//  tempMap.insert(std::pair(MINUS.sym, MINUS));
//  tempMap.insert(std::pair(MULTIPLY.sym, MULTIPLY));
//  tempMap.insert(std::pair(DEVIDE.sym, DEVIDE));
//  tempMap.insert(std::pair(DEVIDE.sym, DEVIDE));
//  tempMap.insert(std::pair(BRACE_OPEN.sym, BRACE_OPEN));
//  tempMap.insert(std::pair(BRACE_CLOSE.sym, BRACE_CLOSE));
//  operatorMap = &tempMap;
}

char Operator::GetOperator() { return sym; }

int Operator::GetPriority() { return priority; }
