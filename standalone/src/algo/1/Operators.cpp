#include "Operators.h"

const Operators Operators::PLUS = Operators('+', 1);
const Operators Operators::MINUS = Operators('-', 1);
const Operators Operators::MULTIPLY = Operators('*', 2);
const Operators Operators::DEVIDE = Operators('/', 2);
const Operators Operators::BRACE_OPEN = Operators('(', 1);
const Operators Operators::BRACE_CLOSE = Operators(')', 3);

const Operators::OperatorMap Operators::operatorMap = {
    {Operators::PLUS.sym, Operators::PLUS},
    {Operators::MINUS.sym, Operators::MINUS},
    {Operators::MULTIPLY.sym, Operators::MULTIPLY},
    {Operators::DEVIDE.sym, Operators::DEVIDE},
    {Operators::BRACE_OPEN.sym, Operators::BRACE_OPEN},
    {Operators::BRACE_CLOSE.sym, Operators::BRACE_CLOSE},
};
