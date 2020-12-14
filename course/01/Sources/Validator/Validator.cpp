#include "Validator.h"

void ip::Validator::validate_line(const std::string &line) {
    if (line.find_first_of('\t') == std::string::npos) {
        std::cerr << "Incorrect line with ip address = " << line << std::endl;
        exit(1);
    }
}
