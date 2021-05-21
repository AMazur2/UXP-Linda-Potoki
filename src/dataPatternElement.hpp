#pragma once

#include <utility>
#include<variant>
#include<string>

enum class Condition {All, Equal, Less, LessEqual, Greater, GreaterEqual, Count};

class DataPatternElement {
    std::variant<std::monostate, std::string, int, double> value;
    Condition condition;

public:
    DataPatternElement() = default;
    DataPatternElement(Condition c, std::variant<std::monostate, std::string, int, double> v);

    std::variant<std::monostate, std::string, int, double> get_value();
    Condition get_condition();

    friend std::ostream &operator<< (std::ostream &os, const DataPatternElement& element);
};