#define BOOST_TEST_MODULE helloworld_test_module

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(ip_filter_test_suite)

BOOST_AUTO_TEST_CASE(if_filter_test) {
        auto actual = read_actual_output();
        auto expected = read_expected_output();
        auto isEqual = std::equal(actual.begin(), actual.end(), expected.begin(), expected.end());
        BOOST_CHECK(isEqual);
}

BOOST_AUTO_TEST_SUITE_END()
