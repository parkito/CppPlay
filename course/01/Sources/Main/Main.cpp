#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

std::vector<std::string> read_input();

std::vector<std::vector<std::string>> format_input(std::vector<std::string> &data);

std::string format_line(std::string &str);

void sort(std::vector<std::vector<std::string>> &data);

void print(std::vector<std::vector<std::string>> &data);

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

std::vector<std::vector<std::string>> format_input(std::vector<std::string> &data) {
    std::vector<std::vector<std::string>> formattedData;
    for (auto &rawLine:data) {
        std::vector<std::string> address;
        auto line = format_line(rawLine);
        for (size_t i = 0, cur = 0; i < line.size(); ++i) {
            if (line[i] == '.') {
                address.push_back(line.substr(cur, i - cur));
                cur = i + 1;
            } else if (i == line.size() - 1) {
                address.push_back(line.substr(cur, i - cur + 1));
            }
        }
        formattedData.push_back(address);
    }

    return formattedData;
}

std::string format_line(std::string &str) {
    return str.substr(0, str.find_first_of('\t'));
}

bool compare11(const std::vector<std::string> &arr1, const std::vector<std::string> &arr2) {
    bool a = std::lexicographical_compare(arr1[0].begin(), arr1[0].end(), arr2[0].begin(), arr2[0].end());
    bool b = std::lexicographical_compare(arr1[1].begin(), arr1[1].end(), arr2[1].begin(), arr2[1].end());
    bool c = std::lexicographical_compare(arr1[2].begin(), arr1[2].end(), arr2[2].begin(), arr2[2].end());
    bool d = std::lexicographical_compare(arr1[3].begin(), arr1[3].end(), arr2[3].begin(), arr2[3].end());

    bool result = false;
    if (arr1[0] != arr2[0]) {
        result = a;
    } else if (arr1[1] != arr2[1]) {
        result = b;
    } else if (arr1[2] != arr2[2]) {
        result = c;
    } else if (arr1[3] != arr2[3]) {
        result = d;
    }

    return !result;
}

void sort(std::vector<std::vector<std::string>> &data) {
    std::sort(data.begin(), data.end(), compare11);
}

void print(std::vector<std::vector<std::string>> &data) {
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


//97.82.75.243 VS 93.179.90.82 -----0 0 1 1 1
//93.179.90.82 VS 97.82.75.243 -----1 1 0 0 1

//93.179.90.82 VS 97.82.75.243 -----1 1 0 0 1
//97.82.75.243 VS 93.179.90.82 -----0 0 1 1 1