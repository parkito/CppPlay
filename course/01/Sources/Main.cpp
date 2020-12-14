#include <iostream>
#include <memory>
#include "Runner/Runner.h"

int main() {
    const std::unique_ptr<ip::Validator> validator{new ip::Validator()};
    const std::unique_ptr<ip::Formatter> formatter{new ip::Formatter};
    const std::unique_ptr<ip::StdReader> stdReader{new ip::StdReader({new ip::Validator()})};

    ip::Runner runner{stdReader, formatter};
    for (auto &line:runner.run()) {
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