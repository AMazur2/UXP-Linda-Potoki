#pragma once

#include<vector>

class DataPatternElement;

class DataPattern {
    std::vector<DataPatternElement> values;

public:
    DataPattern();
    DataPattern(const char* fmt...);

    const DataPatternElement& operator[](std::size_t idx) const;

    int size() const;
};