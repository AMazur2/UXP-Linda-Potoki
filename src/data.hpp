#pragma once

#include<vector>

class DataElement;

class DataPattern;

class Data {
    std::vector<DataElement> values;
public:
    Data();
    Data(const char* fmt...);

    const DataElement& operator[](std::size_t idx) const;

    bool compare(DataPattern pattern) const;
};