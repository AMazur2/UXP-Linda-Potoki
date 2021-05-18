#define BOOST_TEST_MODULE dataElement_test
#include <boost/test/included/unit_test.hpp>
#include<string>

#include"../src/dataElement.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(constructor_test) {
    std::string string_test = "test";
    DataElement string_element(string_test);
    DataElement int_element(5);
    DataElement float_element(9.75);
}

BOOST_AUTO_TEST_CASE(getter_test) {
    std::string string_test = "test";
    DataElement string_element(string_test);
    
    std::string value = std::get<std::string>(string_element.get_value());
    BOOST_CHECK_EQUAL(value, string_test);
}