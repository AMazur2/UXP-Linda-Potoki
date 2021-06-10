#pragma once

#include<boost/serialization/vector.hpp>
#include <boost/serialization/access.hpp>

#include"dataPatternElement.hpp"

class DataPattern {
    std::vector<DataPatternElement> values;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version) {
        ar & values;
    }
public:
    DataPattern();

    DataPattern(const char* fmt...);

    explicit DataPattern(const std::vector<DataPatternElement>& elements);

    const DataPatternElement& operator[](std::size_t idx) const;
    [[nodiscard]] size_t size() const;

    int size() const {return values.size();}

    std::string to_string();

    friend std::ostream &operator<< (std::ostream &os, const DataPattern& data);
};