#pragma once
#include <map>

class Operator {
public:
  static const Operator PLUS;
  static const Operator MINUS;
  static const Operator MULTIPLY;
  static const Operator DEVIDE;
  static const Operator BRACE_OPEN;
  static const Operator BRACE_CLOSE;
//  static const std::map<char, Operator>* operatorMap;

  char GetOperator();
  int GetPriority();

private:
  const char sym;
  const int priority;

  Operator(char sym, int priority);
};