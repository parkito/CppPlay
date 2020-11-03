#pragma once

class Operator{
public:
  Operator(char sym, int priority) : sym(sym), priority(priority){}

  char GetOperator() const;
  int GetPriority() const;
private:
  const char sym;
  const int priority;
};