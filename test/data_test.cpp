#define BOOST_TEST_MODULE data_test
#include <boost/test/included/unit_test.hpp>

#include"../src/data.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(first_test) {
    BOOST_CHECK_EQUAL(2+2, 4);
}
