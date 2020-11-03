#pragma once

#include <map>

#include "Operator.h"

class Operators {
public:
  static const Operator PLUS;
  static const Operator MINUS;
  static const Operator MULTIPLY;
  static const Operator DEVIDE;
  static const Operator BRACE_OPEN;
  static const Operator BRACE_CLOSE;

//  typedef std::map<const char, Operator> OperatorMap;
//
//  static const OperatorMap operatorMap;
};
