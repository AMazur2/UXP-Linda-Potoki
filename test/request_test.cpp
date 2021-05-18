#define BOOST_TEST_MODULE request_test
#include <boost/test/included/unit_test.hpp>

#include"../src/request.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(first_test) {
    BOOST_CHECK_EQUAL(2+2, 4);
}
