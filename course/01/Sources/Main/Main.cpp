#include <iostream>
#include <vector>
#include <algorithm>
#include "IpFilter.h"
#include "Reader.h"
#include "IpCommon.h"


ip::Data format_input(ip::Input &data);

std::string format_line(std::string &str);

void sort(ip::Data &data);

bool compare(const ip::Address &arr1, const ip::Address &arr2);

bool compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index);

void print(ip::Data &data);

int main() {
    ip::Reader reader;
    auto input = reader.read_input();
    auto formattedInput = format_input(input);
    sort(formattedInput);
    print(formattedInput);
    return 0;
}

ip::Data format_input(ip::Input &data) {
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

std::string format_line(std::string &str) {
    return str.substr(0, str.find_first_of('\t'));
}

void sort(ip::Data &data) {
    std::sort(data.begin(), data.end(), compare);
}

bool compare(const ip::Address &arr1, const ip::Address &arr2) {
    bool result = false;

    for (size_t i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            result = compare_indexed(arr1, arr2, i);
            break;
        }
    }

    return !result;
}

bool compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index) {
    return arr1[index] < arr2[index];
}

void print(ip::Data &data) {
    for (auto &line:data) {
        for (size_t i = 0; i < line.size(); ++i) {
            if (i != 3) {
                std::cout << line[i] << ".";
            } else {
                std::cout << line[i] << std::endl;
            }
        }
    }
}

//    std::ifstream file(argv[1]);
//    if (!file.is_open()) {
//        std::cerr << "Can open " << argv[0];
//        exit(1);
//    }
//    while (getline(file, line)) {
//    }
//    file.close();

//    std::ostringstream oss;
//    std::copy(arr.begin(), arr.end(), std::ostream_iterator<std::string>(oss, "."));
//    std::cout << oss.str() << std::endl;