#pragma once

#include <iostream>
#include <vector>

namespace ip {
    using Input = std::vector<std::string>;
    using Output = std::vector<std::string>;
    using Address = std::vector<unsigned int>;
    using Data = std::vector<ip::Address>;
}