#define BOOST_TEST_MODULE helloworld_test_module

#include <boost/test/unit_test.hpp>
#include "Calculator.h"

BOOST_AUTO_TEST_SUITE(allocator_test_suite)

    BOOST_AUTO_TEST_CASE(fa_0) {
        BOOST_CHECK(Calculator::calculate_fa(0) == 1);
    }

    BOOST_AUTO_TEST_CASE(fa_1) {
        BOOST_CHECK(Calculator::calculate_fa(1) == 1);
    }

    BOOST_AUTO_TEST_CASE(fa_2) {
        BOOST_CHECK(Calculator::calculate_fa(2) == 2);
    }

    BOOST_AUTO_TEST_CASE(fa_3) {
        BOOST_CHECK(Calculator::calculate_fa(3) == 6);
    }

    BOOST_AUTO_TEST_CASE(fa_10) {
        BOOST_CHECK(Calculator::calculate_fa(10) == 3628800);
    }

    BOOST_AUTO_TEST_CASE(fi_0) {
        BOOST_CHECK(Calculator::calculate_fi(0) == 0);
    }

    BOOST_AUTO_TEST_CASE(fi_1) {
        BOOST_CHECK(Calculator::calculate_fi(1) == 1);
    }

    BOOST_AUTO_TEST_CASE(fi_2) {
        BOOST_CHECK(Calculator::calculate_fi(2) == 1);
    }

    BOOST_AUTO_TEST_CASE(fi_3) {
        BOOST_CHECK(Calculator::calculate_fi(3) == 2);
    }

    BOOST_AUTO_TEST_CASE(fi_10) {
        BOOST_CHECK(Calculator::calculate_fi(10) == 55);
    }

BOOST_AUTO_TEST_SUITE_END()
