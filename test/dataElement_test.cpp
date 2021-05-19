#define BOOST_TEST_MODULE dataElement_test
#include <boost/test/included/unit_test.hpp>
#include<string>

#include"../src/dataElement.hpp"
#include"../src/dataPatternElement.hpp"

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

BOOST_AUTO_TEST_CASE(compare_equal_test) {
    DataElement data_element(5);
    DataPatternElement data_pattern_element(Condition::Equal, 5);
    BOOST_ASSERT(data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_equal_false_test) {
    DataElement data_element(5);
    DataPatternElement data_pattern_element(Condition::Equal, 6);
    BOOST_ASSERT(!data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_less_test) {
    DataElement data_element(5);
    DataPatternElement data_pattern_element(Condition::Less, 6);
    BOOST_ASSERT(data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_less_false_test) {
    DataElement data_element(7);
    DataPatternElement data_pattern_element(Condition::Less, 6);
    BOOST_ASSERT(!data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_greater_test) {
    DataElement data_element(7);
    DataPatternElement data_pattern_element(Condition::Greater, 6);
    BOOST_ASSERT(data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_greater_false_test) {
    DataElement data_element(5);
    DataPatternElement data_pattern_element(Condition::Greater, 6);
    BOOST_ASSERT(!data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_equal_string_test) {
    DataElement data_element("aaa");
    DataPatternElement data_pattern_element(Condition::Equal, "aaa");
    BOOST_ASSERT(data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_less_string_test) {
    DataElement data_element("aaa");
    DataPatternElement data_pattern_element(Condition::Less, "aba");
    BOOST_ASSERT(data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_less_string_false_test) {
    DataElement data_element("aca");
    DataPatternElement data_pattern_element(Condition::Less, "aba");
    BOOST_ASSERT(!data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_less_equal_string_test) {
    DataElement data_element("aca");
    DataPatternElement data_pattern_element(Condition::LessEqual, "aca");
    BOOST_ASSERT(data_element.compare(data_pattern_element));
}

BOOST_AUTO_TEST_CASE(compare_less_equal_float_test) {
    DataElement data_element(1.0);
    DataPatternElement data_pattern_element(Condition::LessEqual, 1.5);
    BOOST_ASSERT(data_element.compare(data_pattern_element));
}