#include <iostream>
#include <map>
#include "FaFi.h"
#include "Calculator.h"

int main() {
    auto map = std::map<int, FaFi>{};

    for (int i = 0; i < 10; ++i) {
        auto fafi = FaFi(Calculator::calculate_fa(i), Calculator::calculate_fi(i));
        map.emplace(i, fafi);
    }

    for (auto &el: map) {
        std::cout << "Key = " << el.first << " FA = " << el.second.get_fa() << " FI = " << el.second.get_fi()
                  << std::endl;
    }
}


