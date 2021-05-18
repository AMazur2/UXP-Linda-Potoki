#define BOOST_TEST_MODULE dataPatternElement_test
#include <boost/test/included/unit_test.hpp>

#include"../src/dataPatternElement.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(constructor_test) {
    DataPatternElement(Condition::Less, "string");
}

BOOST_AUTO_TEST_CASE(access_int_test) {
    DataPatternElement element(Condition::Equal, 5);
    BOOST_CHECK_EQUAL(std::get<int>(element.get_value()), 5);
}

BOOST_AUTO_TEST_CASE(access_string_test) {
    DataPatternElement element(Condition::Equal, "test");
    BOOST_CHECK_EQUAL(std::get<std::string>(element.get_value()), "test");
}

BOOST_AUTO_TEST_CASE(access_float_test) {
    DataPatternElement element(Condition::Equal, 1.5);
    BOOST_CHECK_EQUAL(std::get<double>(element.get_value()), 1.5);
}