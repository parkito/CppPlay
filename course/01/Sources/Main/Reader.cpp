#include "Reader.h"

ip::Input ip::Reader::read_input() {
    ip::Input data;
    for (std::string line; std::getline(std::cin, line);) {
        data.push_back(line);
    }
    return data;
}
