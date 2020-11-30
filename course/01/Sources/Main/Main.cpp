#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

using Input = std::vector<std::string>;
using Data = std::vector<std::vector<unsigned int>>;
using Address = std::vector<unsigned int>;

Input read_input();

Data format_input(Input &data);

std::string format_line(std::string &str);

void sort(Data &data);

bool compare(const Address &arr1, const Address &arr2);

bool compare_indexed(const Address &arr1, const Address &arr2, int index);

void print(Data &data);

int main() {
    auto input = read_input();
    auto formattedInput = format_input(input);
    sort(formattedInput);
    print(formattedInput);
    return 0;
}

Input read_input() {
    Input data;
    for (std::string line; std::getline(std::cin, line);) {
        data.push_back(line);
    }
    return data;
}

Data format_input(Input &data) {
    Data formattedData;
    for (auto &rawLine:data) {
        Address address;
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

void sort(Data &data) {
    std::sort(data.begin(), data.end(), compare);
}

bool compare(const Address &arr1, const Address &arr2) {
    bool result = false;

    for (size_t i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            result = compare_indexed(arr1, arr2, i);
            break;
        }
    }

    return !result;
}

bool compare_indexed(const Address &arr1, const Address &arr2, int index) {
    return arr1[index] < arr2[index];
}

void print(Data &data) {
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