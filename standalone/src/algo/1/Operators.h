#pragma once

#include <map>

class Operators {
public:
  static const Operators PLUS;
  static const Operators MINUS;
  static const Operators MULTIPLY;
  static const Operators DEVIDE;
  static const Operators BRACE_OPEN;
  static const Operators BRACE_CLOSE;

  typedef std::map<char, Operators> OperatorMap;
  static const OperatorMap operatorMap;

private:
  const char sym;
  const int priority;
  Operators(char sym, int priority) : sym(sym), priority(priority){};
};
