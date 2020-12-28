#include <iostream>
#include <map>
#include "FaFi.h"
#include "Calculator.h"

int main() {
//    auto mp = std::map<int, FaFi>();
    std::cout << Calculator::calculate_fa(6)<<std::endl;

    std::cout << Calculator::calculate_fi(10);
}


