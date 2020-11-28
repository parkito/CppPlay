#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include<boost/tokenizer.hpp>

std::vector<std::string> read_input();

std::vector<std::array<std::string, 4>> format_input(std::vector<std::string> &data);

std::string format_line(std::string &str);

void sort(std::vector<std::array<std::string, 4>> &data);

void print(std::vector<std::array<std::string, 4>> &data);

int main() {
    auto input = read_input();
    auto formattedInput = format_input(input);
    sort(formattedInput);
    print(formattedInput);
    return 0;
}

std::vector<std::string> read_input() {
    std::vector<std::string> data;
    for (std::string line; std::getline(std::cin, line);) {
        data.push_back(line);
    }
    return data;
}

std::vector<std::array<std::string, 4>> format_input(std::vector<std::string> &data) {
    std::vector<std::array<std::string, 4>> formattedData;
    boost::char_separator<char> sep(".");
    for (auto &rawLine:data) {
        std::array<std::string, 4> lineArr;
        auto line = format_line(rawLine);
        boost::tokenizer<boost::char_separator<char>> tok(line, sep);
        int curIndex = 0;
        for (auto cur = tok.begin(); cur != tok.end(); ++cur) {
            lineArr[curIndex++] = *cur;
        }
        formattedData.push_back(lineArr);
    }

    return formattedData;
}

std::string format_line(std::string &str) {
    return str.substr(0, str.find('\t'));
}

void sort(std::vector<std::array<std::string, 4>> &data) {

}

void print(std::vector<std::array<std::string, 4>> &data) {
    for (auto &line:data) {
        for (int i = 0; i < 4; ++i) {
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
