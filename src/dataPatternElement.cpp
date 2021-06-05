#include<iostream>
#include <utility>

#include"dataPatternElement.hpp"

std::variant<std::monostate, std::string, int, double> DataPatternElement::get_value() {return value;}
Condition DataPatternElement::get_condition() {return condition;}

std::string to_string(Condition condition) {
    switch (condition) {
        case Condition::All:
            return "All like ";
        case Condition::Equal:
            return "=";
        case Condition::Greater:
            return ">";
        case Condition::GreaterEqual:
            return ">=";
        case Condition::Less:
            return "<";
        case Condition::LessEqual:
            return "<=";
        default:
            return "";
    }
}

std::ostream &operator<< (std::ostream &os, const DataPatternElement& element) {
    if (boost::holds_alternative<std::string>(element.value)) {
        os << to_string(element.condition) << boost::get<std::string>(element.value);
    } else if (boost::holds_alternative<int>(element.value)) {
        os << to_string(element.condition) << boost::get<int>(element.value);
    } else if (boost::holds_alternative<double>(element.value)) {
        os << to_string(element.condition) << boost::get<double>(element.value);
    }
    return os;
}

DataPatternElement::DataPatternElement(Condition c, std::variant<std::monostate, std::string, int, double> v)
        : condition{c}, value{std::move(v)} {}