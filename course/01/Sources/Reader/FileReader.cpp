#include "FileReader.h"
#include <fstream>

ip::Input ip::FileReader::read_input(std::optional<std::string> filePath) {
    ip::Input data;
    if (!filePath.has_value()) {
        throw std::runtime_error("File is not present");
    }
    std::ifstream file("numbers.txt");
    for (std::string line; std::getline(file, line);) {
        validator->validate_line(line);
        data.push_back(line);
    }
    return data;
}
