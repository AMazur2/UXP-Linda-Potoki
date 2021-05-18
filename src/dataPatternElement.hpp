#pragma once

#include<variant>
#include<string>

enum class Condition {All, Equal, Less, LessEqual, Greater, GreaterEqual};

class DataPatternElement {
    std::variant<std::string, int, double> value;
    Condition condition;

public:
    DataPatternElement(Condition c, std::variant<std::string, int, double> v);

    std::variant<std::string, int, double> get_value();
    Condition get_condition();
};