#define BOOST_TEST_MODULE data_test
#include <boost/test/included/unit_test.hpp>
#include <variant>

#include"../src/data.hpp"
#include"../src/dataElement.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(constructor_test) {
    Data data("isf", 1, "string", 0.5);
}

BOOST_AUTO_TEST_CASE(access_int_test) {
    Data data("isf", 1, "string", 0.5);
    DataElement element0 = data[0];
    int element_int = std::get<int>(element0.get_value());
    BOOST_CHECK_EQUAL(element_int, 1);
}

BOOST_AUTO_TEST_CASE(access_string_test) {
    Data data("isf", 1, "string", 0.5);
    DataElement element1 = data[1];
    std::string element_string = std::get<std::string>(element1.get_value());
    BOOST_CHECK_EQUAL(element_string, "string");
}

BOOST_AUTO_TEST_CASE(access_double_test) {
    Data data("isf", 1, "string", 0.5);
    DataElement element2 = data[2];
    double element_double = std::get<double>(element2.get_value());
    BOOST_CHECK_EQUAL(element_double, 0.5);
}