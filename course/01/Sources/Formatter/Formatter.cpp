#include "Formatter.h"

ip::Data ip::Formatter::format_input(ip::Input &data) {
    ip::Data formattedData;
    for (auto &rawLine:data) {
        ip::Address address;
        auto line = format_line(rawLine);
        for (size_t i = 0, cur = 0; i < line.size(); ++i) {
            if (line[i] == '.') {
                address.push_back(std::stoi(line.substr(cur, i - cur)));
                cur = i + 1;
            } else if (i == line.size() - 1) {
                address.push_back(std::stoi(line.substr(cur, i - cur + 1)));
            }
        }
        formattedData.push_back(address);
    }

    return formattedData;
}

std::string ip::Formatter::format_line(std::string &str) {
    return str.substr(0, str.find_first_of('\t'));
}
