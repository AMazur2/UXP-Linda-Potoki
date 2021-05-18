#pragma once

#include<vector>

#include"dataElement.hpp"

class Data {
    std::vector<DataElement> values;
public:
    Data();
    Data(const char* fmt...);

    const DataElement& operator[](std::size_t idx) const;
};