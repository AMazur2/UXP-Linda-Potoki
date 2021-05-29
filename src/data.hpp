#pragma once

#include<boost/serialization/vector.hpp>
#include <boost/serialization/access.hpp>

#include"dataElement.hpp"

#include"dataPatternElement.hpp"
#include"dataPattern.hpp"

class Data {
    std::vector<DataElement> values;
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & values;
    }
public:
    Data();
    Data(const char* fmt...);

    const DataElement& operator[](std::size_t idx) const;

    bool compare(DataPattern pattern) const;
};