#pragma once

#include<variant>
#include<string>
#include <boost/serialization/access.hpp>
#include <boost/variant.hpp>

#include"dataPatternElement.hpp"

class DataElement {
    boost::variant<std::string, int, double> value;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & value;
    }
public:
    DataElement();
    DataElement(boost::variant<std::string, int, double> s);
    boost::variant<std::string, int, double> get_value();

    bool compare(DataPatternElement pattern_element) const;
};