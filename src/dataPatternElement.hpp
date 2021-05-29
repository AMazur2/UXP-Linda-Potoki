#pragma once

#include<variant>
#include<string>
#include <boost/serialization/access.hpp>
#include <boost/variant.hpp>

enum class Condition {All, Equal, Less, LessEqual, Greater, GreaterEqual};

class DataPatternElement {
    boost::variant<std::string, int, double> value;
    Condition condition;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & value;
    }
public:
    DataPatternElement(Condition c, boost::variant<std::string, int, double> v) : condition{c}, value{v} {}

    boost::variant<std::string, int, double> get_value() {return value;}
    Condition get_condition()  {return condition;}
};