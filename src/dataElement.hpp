#pragma once

#include<variant>
#include<string>

class DataPatternElement;

class DataElement {
    std::variant<std::string, int, double> value;

public:
    DataElement(std::variant<std::string, int, double> s);
    std::variant<std::string, int, double> get_value();

    bool compare(DataPatternElement pattern_element) const;
};