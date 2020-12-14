#include "StdReader.h"

ip::Input ip::StdReader::read_input(std::optional<std::string>) {
    ip::Input data;
    for (std::string line; std::getline(std::cin, line);) {
        validator.validate_line(line);
        data.push_back(line);
    }
    return data;
}