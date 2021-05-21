#define BOOST_TEST_MODULE request_test
#include <boost/test/included/unit_test.hpp>
#include <variant>

#include"../src/request.hpp"

using namespace boost::unit_test;


BOOST_AUTO_TEST_CASE(constructor_test) {
    Data data("i", 5);
    pid_t pid = 123;
    Request(data, RequestAction::Output, pid, time(NULL));
}

BOOST_AUTO_TEST_CASE(access_data_test) {
    Data data("i", 5);
    pid_t pid = 123;
    Request request(data, RequestAction::Output, pid, time(NULL));
    Data request_data = std::get<Data>(request.get_data());
    DataElement element = request_data[0];
    BOOST_CHECK_EQUAL(std::get<int>(element.get_value()), 5);
}

BOOST_AUTO_TEST_CASE(access_pid_test) {
    Data data("i", 5);
    pid_t pid = 123;
    Request request(data, RequestAction::Output, pid, time(NULL));
    BOOST_CHECK_EQUAL(request.get_pid(), pid);
}