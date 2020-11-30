#include <iostream>
#include <vector>
#include <algorithm>
#include <array>

std::vector<std::string> read_input();

std::vector<std::vector<std::string>> format_input(std::vector<std::string> &data);

std::string format_line(std::string &str);

void sort(std::vector<std::vector<std::string>> &data);

bool compare(const std::vector<std::string> &arr1, const std::vector<std::string> &arr2);

bool compare_indexed(const std::vector<std::string> &arr1, const std::vector<std::string> &arr2, int index);

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

void sort(std::vector<std::vector<std::string>> &data) {
    std::sort(data.begin(), data.end(), compare);
}

bool compare(const std::vector<std::string> &arr1, const std::vector<std::string> &arr2) {
    bool result = false;

    for (size_t i = 0; i < arr1.size(); ++i) {
        if (arr1[i] != arr2[i]) {
            result = compare_indexed(arr1, arr2, i);
            break;
        }
    }

    return !result;
}

bool compare_indexed(const std::vector<std::string> &arr1, const std::vector<std::string> &arr2, int index) {
    return std::lexicographical_compare(arr1[index].begin(), arr1[index].end(), arr2[index].begin(), arr2[index].end());
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