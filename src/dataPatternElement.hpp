#pragma once

#include <utility>
#include<variant>
#include<string>
#include <boost/serialization/access.hpp>
#include <boost/variant.hpp>

enum class Condition {All, Equal, Less, LessEqual, Greater, GreaterEqual, Count};

class DataPatternElement {

    boost::variant<std::string, int, double> value;

    Condition condition;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & value;
        ar & condition;
    }
public:
    DataPatternElement(Condition c, boost::variant<std::string, int, double> v) : condition{c}, value{v} {}
    DataPatternElement() : condition(Condition::Count), value(0) {};
    boost::variant<std::string, int, double> get_value() {return value;}
    Condition get_condition()  {return condition;}

    friend std::ostream &operator<< (std::ostream &os, const DataPatternElement& element);
};