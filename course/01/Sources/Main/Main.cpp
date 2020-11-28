#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char **argv) {
    std::cout << argc;
    if (argc != 2) {
        std::cerr << "You should enter the name of file\n";
        exit(1);
    }
    std::ifstream file(argv[0]);
    if (!file.is_open()) {
        std::cerr << "Can open " << argv[0];
        exit(1);
    }

    std::vector<std::string> rawData;
    std::string line;
    while (getline(file, line)) {
        rawData.push_back(line);
    }
    file.close();

    for (auto &el:rawData) {
        std::cout << el;
    }

    return 0;
}
