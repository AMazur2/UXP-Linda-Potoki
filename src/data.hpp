#pragma once

#include<vector>

#include"dataElement.hpp"

#include"dataPatternElement.hpp"
#include"dataPattern.hpp"

class Data {
    std::vector<DataElement> values;
public:
    Data();
    Data(const char* fmt...);

    const DataElement& operator[](std::size_t idx) const;

    bool compare(DataPattern pattern) const;
};