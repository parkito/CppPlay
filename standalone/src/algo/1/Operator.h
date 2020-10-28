#pragma once

class Operator {
public:
  static const Operator PLUS;
  static const Operator MINUS;
  static const Operator MULTIPLY;
  static const Operator DEVIDE;
  static const Operator BRACE_OPEN;
  static const Operator BRACE_CLOSE;

private:
  const char sym;
  const int priority;
  Operator(char sym, int priority) : sym(sym), priority(priority){};
};
