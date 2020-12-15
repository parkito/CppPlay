#define BOOST_TEST_MODULE helloworld_test_module

#include <boost/test/unit_test.hpp>
#include <FileReader.h>
#include <fstream>
#include <iostream>
#include "../Sources/Runner/Runner.h"

ip::Output read_actual_output() {
    std::unique_ptr<ip::Validator> validator{new ip::Validator()};
    std::unique_ptr<ip::Formatter> formatter{new ip::Formatter};
    std::unique_ptr<ip::IReader> fileReader{new ip::FileReader{validator}};
    std::unique_ptr<ip::LexicographicComparator> comparator{new ip::LexicographicComparator};
    ip::Runner runner{fileReader, formatter, comparator};

    const ip::Output &actual = runner.run("../Resources/ip_filter.tsv");
    return actual;
}

ip::Output read_expected_output() {
    ip::Output expected;
    std::ifstream checkFile;
    checkFile.open("../Resources/ip_filter.tst");
    if (checkFile.is_open()) {
        for (std::string line; std::getline(checkFile, line);) {
            expected.push_back(line);
        }
    }
    checkFile.close();
    return expected;
}

BOOST_AUTO_TEST_SUITE(ip_filter_test_suite)

    BOOST_AUTO_TEST_CASE(if_filter_test) {
        auto actual = read_actual_output();
        auto expected = read_expected_output();
        auto isEqual = std::equal(actual.begin(), actual.end(), expected.begin(), expected.end());
        auto v = expected[1042];
        for (size_t i = 0; i < actual.size(); ++i) {
            if (actual[i] != expected[i]) {
                std::cout << i << " " << actual[i] << " " << expected[i] << std::endl;
            }
        }

        BOOST_CHECK(isEqual);
    }

BOOST_AUTO_TEST_SUITE_END()
