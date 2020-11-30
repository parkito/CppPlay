#include "Reader.h"

ip::Reader::Reader(const ip::Validator &validator) : validator{validator} {}

ip::Input ip::Reader::read_input() {
    ip::Input data;
    for (std::string line; std::getline(std::cin, line);) {
        validator.validate_line(line);
        data.push_back(line);
    }
    return data;
}
