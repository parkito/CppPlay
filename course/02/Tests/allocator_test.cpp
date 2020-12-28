#define BOOST_TEST_MODULE helloworld_test_module

#include <boost/test/unit_test.hpp>
#include "../Sources/Calculator.h"

BOOST_AUTO_TEST_SUITE(allocator_test_suite)

    BOOST_AUTO_TEST_CASE(fa_0) {
        BOOST_CHECK(Calculator::calculate_fa(0) == 1);
    }

    BOOST_AUTO_TEST_CASE(fa_1) {
        BOOST_CHECK(Calculator::calculate_fa(1) == 2);
    }

BOOST_AUTO_TEST_SUITE_END()
