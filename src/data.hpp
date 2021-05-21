#pragma once

#include<vector>

#include"dataElement.hpp"

#include"dataPatternElement.hpp"
#include"dataPattern.hpp"

class Data {
    std::vector<DataElement> values;
public:
    Data();
    explicit Data(const char* fmt...);
    explicit Data(const std::vector<DataElement>& elements);

    const DataElement& operator[](std::size_t idx) const;
    [[nodiscard]] bool compare(const DataPattern& pattern) const;
    [[nodiscard]] size_t size() const;

    friend std::ostream &operator<< (std::ostream &os, const Data& data);
};