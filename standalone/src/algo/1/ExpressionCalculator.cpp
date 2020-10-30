#include "ExpressionCalculator.h"

double ExpressionCalculator::Calculate() { return 0.0; }

ExpressionHolder ExpressionCalculator::ToHolder(std::string& expression) {
  ExpressionHolder holder = ExpressionHolder();
  for (char& sym : expression) {
  }
  return ExpressionHolder();
}

void ParseSymbol(ExpressionHolder holder, char sym) {
  std::map<char, Operators> map = Operators::operatorMap;
  Operators op = map[sym];
  if (auto it = map.find(sym); it != map.end()) {
    holder.AddOperator(it->second);
    return;
  }
  holder.AddValue((int)sym);
}