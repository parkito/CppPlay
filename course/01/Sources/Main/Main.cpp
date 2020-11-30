#include <iostream>
#include <vector>
#include <algorithm>
#include "Applier.h"
#include "Reader.h"
#include "Formatter.h"
#include "IpCommon.h"
#include "Runner.h"

void sort(ip::Data &data);

bool compare(const ip::Address &arr1, const ip::Address &arr2);

bool compare_indexed(const ip::Address &arr1, const ip::Address &arr2, int index);

void print(ip::Data &data);

int main() {
    ip::Runner runner;
    ip::Output &output = runner.run();

    for (auto &line:output) {
        std::cout << line << std::endl;
    }
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