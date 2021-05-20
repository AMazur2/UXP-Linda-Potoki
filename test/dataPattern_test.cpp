#define BOOST_TEST_MODULE dataPattern_test
#include <boost/test/included/unit_test.hpp>

#include"../src/dataPattern.hpp"
#include"../src/dataPatternElement.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(constructor_test) {
    DataPattern pattern("iisf", Condition::Equal, 5, Condition::GreaterEqual, 1, Condition::Less, "abc", Condition::All, 0.0);
}

BOOST_AUTO_TEST_CASE(access_int_test) {
    DataPattern data("isf", Condition::Equal, 1, Condition::Equal, "string", Condition::Equal, 0.5);
    DataPatternElement element0 = data[0];
    int element_int = std::get<int>(element0.get_value());
    BOOST_CHECK_EQUAL(element_int, 1);
}

BOOST_AUTO_TEST_CASE(access_string_test) {
    DataPattern data("isf", Condition::Equal, 1, Condition::Equal, "string", Condition::Equal, 0.5);
    DataPatternElement element1 = data[1];
    std::string element_string = std::get<std::string>(element1.get_value());
    BOOST_CHECK_EQUAL(element_string, "string");
}

BOOST_AUTO_TEST_CASE(access_double_test) {
    DataPattern data("isf", Condition::Equal, 1, Condition::Equal, "string", Condition::Equal, 0.5);
    DataPatternElement element2 = data[2];
    double element_double = std::get<double>(element2.get_value());
    BOOST_CHECK_EQUAL(element_double, 0.5);
}