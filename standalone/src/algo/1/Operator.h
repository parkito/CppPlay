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

const Operator Operator::PLUS = Operator('+', 1);
const Operator Operator::MINUS = Operator('-', 1);
const Operator Operator::MULTIPLY = Operator('*', 2);
const Operator Operator::DEVIDE = Operator('/', 2);
const Operator Operator::BRACE_OPEN = Operator('(', 1);
const Operator Operator::BRACE_CLOSE = Operator(')', 3);
