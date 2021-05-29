#pragma once

#include<variant>
#include<string>

#include"dataPatternElement.hpp"

class DataElement {
    std::variant<std::monostate, std::string, int, double> value;

public:
    DataElement();
    explicit DataElement(std::variant<std::monostate, std::string, int, double> s);
    std::variant<std::monostate, std::string, int, double> get_value();

    [[nodiscard]] bool compare(DataPatternElement pattern_element) const;

    friend std::ostream &operator<< (std::ostream &os, const DataElement& element);
};