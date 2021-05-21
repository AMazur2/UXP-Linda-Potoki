#define BOOST_TEST_MODULE response_test
#include <boost/test/included/unit_test.hpp>

#include"../src/response.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(constructor_test) {
    Data data("s", "test");
    Response response(data);
}

BOOST_AUTO_TEST_CASE(access_test) {
    Data data("s", "test");
    Response response(data);
    DataElement element = response.get_data()[0];
    BOOST_CHECK_EQUAL(std::get<std::string>(element.get_value()), "test");
}
