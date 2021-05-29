#pragma once

#include<vector>

#include"dataPatternElement.hpp"

class DataPattern {
    std::vector<DataPatternElement> values;

public:
    DataPattern();
    explicit DataPattern(const char* fmt...);
    explicit DataPattern(const std::vector<DataPatternElement>& elements);

    const DataPatternElement& operator[](std::size_t idx) const;
    [[nodiscard]] size_t size() const;

    friend std::ostream &operator<< (std::ostream &os, const DataPattern& data);
};