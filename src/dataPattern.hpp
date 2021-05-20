#pragma once

#include<vector>

#include"dataPatternElement.hpp"

class DataPattern {
    std::vector<DataPatternElement> values;

public:
    DataPattern();
    DataPattern(const char* fmt...);

    const DataPatternElement& operator[](std::size_t idx) const { return values[idx]; }

    int size() const {return values.size();}
};