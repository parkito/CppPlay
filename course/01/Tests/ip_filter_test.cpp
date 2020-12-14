#define BOOST_TEST_MODULE helloworld_test_module

#include <boost/test/unit_test.hpp>
#include "../Sources/Runner/Runner.h"

BOOST_AUTO_TEST_SUITE(ip_filter_test_suite)

    BOOST_AUTO_TEST_CASE(if_filter_test) {
        for (auto &line:ip::Runner().run()) {
            std::cout << line << std::endl;
        }
        BOOST_CHECK(1 == 1);
    }

BOOST_AUTO_TEST_SUITE_END()
