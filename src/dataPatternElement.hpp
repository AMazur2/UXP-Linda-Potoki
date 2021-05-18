#pragma once

#include<variant>

enum class Condition {All, Equal, Less, LessEqual, Greater, GreaterEqual};

class DataPatternElement {
    std::variant<std::string, int, double> value;
    Condition condition;
};