#include <iostream>
#include <memory>
#include "Runner/Runner.h"

int main() {
    std::unique_ptr<ip::Validator> validator{new ip::Validator()};
    std::unique_ptr<ip::Formatter> formatter{new ip::Formatter};
    std::unique_ptr<ip::IReader> stdReader{new ip::StdReader{validator}};
    std::unique_ptr<ip::LexicographicComparator> comparator{new ip::LexicographicComparator};
    ip::Runner runner{stdReader, formatter, comparator};

    for (auto &line:runner.run(std::nullopt)) {
        std::cout << line << std::endl;
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