//
// Created by aniela on 5/21/21.
//

#define BOOST_TEST_MODULE dataPattern_test
#include <boost/test/included/unit_test.hpp>

#include"../src/dataGenerator.hpp"

using namespace boost::unit_test;

BOOST_AUTO_TEST_CASE(condition_test) {
    DataGenerator gen(5, 10, 10, 10);
    for (int i = 0; i < 20; i++) {
        Condition condition = gen.next_condition();
        BOOST_CHECK(condition == Condition::All
                    || condition == Condition::Equal
                    || condition == Condition::Greater
                    || condition == Condition::GreaterEqual
                    || condition == Condition::Less
                    || condition == Condition::LessEqual
        );
    }
}

BOOST_AUTO_TEST_CASE(type_test) {
    DataGenerator gen(5, 10, 10, 10);
    for (int i = 0; i < 20; i++) {
        Type type = gen.next_type();
        BOOST_CHECK(type == Type::String
                    || type == Type::Int
                    || type == Type::Real
        );
    }
}

BOOST_AUTO_TEST_CASE(data_test) {
    DataGenerator gen(5, 10, 10, 10);
    for (int i = 0; i < 20; i++) {
        Data data = gen.next_data();
        BOOST_CHECK(data.size() <= 5);
    }
}

BOOST_AUTO_TEST_CASE(data_pattern_test) {
    DataGenerator gen(5, 10, 10, 10);
    for (int i = 0; i < 20; i++) {
        DataPattern data_pattern = gen.next_data_pattern();
        BOOST_CHECK(data_pattern.size() <= 5);
    }
}