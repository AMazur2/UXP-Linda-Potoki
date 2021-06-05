#pragma once

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
    }
public:
    DataPatternElement() = default;
    DataPatternElement(Condition c, std::variant<std::monostate, std::string, int, double> v);

    std::variant<std::monostate, std::string, int, double> get_value();
    Condition get_condition();

    friend std::ostream &operator<< (std::ostream &os, const DataPatternElement& element);
};