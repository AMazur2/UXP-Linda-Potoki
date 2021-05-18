#pragma once

#include<variant>
#include<string>

class DataElement {
    std::variant<std::string, int, double> value;

public:
    DataElement(std::variant<std::string, int, double> s);
    std::variant<std::string, int, double> get_value();
};