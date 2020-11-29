#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include<boost/tokenizer.hpp>
#include <cstring>

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

bool compare11(const std::array<std::string, 4> &arr1, const std::array<std::string, 4> &arr2) {
    std::cout << arr1[0] << "." << arr1[1] << "." << arr1[2] << "." << arr1[3] << " VS " << arr2[0] << "." << arr2[1]
              << "." << arr2[2] << "." << arr2[3] << " ";;
    bool a = std::lexicographical_compare(arr1[0].begin(), arr1[0].end(), arr2[0].begin(), arr2[0].end());
    bool b = std::lexicographical_compare(arr1[1].begin(), arr1[1].end(), arr2[1].begin(), arr2[1].end());
    bool c = std::lexicographical_compare(arr1[2].begin(), arr1[2].end(), arr2[2].begin(), arr2[2].end());
    bool d = std::lexicographical_compare(arr1[3].begin(), arr1[3].end(), arr2[3].begin(), arr2[3].end());
    std::cout << a << " " << b << " " << c << " " << d << " " << (a || b || c || d) << " " << std::endl;

    return a;
}

void sort(std::vector<std::array<std::string, 4>> &data) {
    std::sort(data.begin(), data.end(), compare11);
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
    std::cout << "done----------------";
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
