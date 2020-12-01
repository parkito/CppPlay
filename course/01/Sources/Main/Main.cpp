#include <iostream>
#include "Runner.h"

int main() {
    ip::Runner runner;
    ip::Output output = runner.run();

    for (auto &line:output) {
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