#include"dataElement.hpp"

#include <iostream>
#include <utility>
#include"dataPatternElement.hpp"

DataElement::DataElement(std::variant<std::monostate, std::string, int, double> s) : value{std::move(s)} {}
std::variant<std::monostate, std::string, int, double> DataElement::get_value() {return value;}

bool DataElement::compare(DataPatternElement pattern_element) const {
    if (std::holds_alternative<int>(value) && std::holds_alternative<int>(pattern_element.get_value()) 
    || std::holds_alternative<double>(value) && std::holds_alternative<double>(pattern_element.get_value())) {
        switch(pattern_element.get_condition()) {
            case Condition::All:
                return true;
            case Condition::Equal:
                return value == pattern_element.get_value();
            case Condition::Greater:
                return value > pattern_element.get_value();
            case Condition::GreaterEqual:
                return value >= pattern_element.get_value();
            case Condition::Less:
                return value < pattern_element.get_value();      
            case Condition::LessEqual:
                return value <= pattern_element.get_value();
            default:
                return false;
        }
    } else if (std::holds_alternative<std::string>(value) 
    && std::holds_alternative<std::string>(pattern_element.get_value())) {
        std::string element_string_value = std::get<std::string>(value);
        std::string pattern_string_value = std::get<std::string>(pattern_element.get_value());

        switch(pattern_element.get_condition()) {
            case Condition::All:
                return true;
            case Condition::Equal:
                return element_string_value == pattern_string_value;
            case Condition::Greater:
                return element_string_value.compare(pattern_string_value) > 0;
            case Condition::GreaterEqual:
                return element_string_value.compare(pattern_string_value) >= 0;
            case Condition::Less:
                return element_string_value.compare(pattern_string_value) < 0;
            case Condition::LessEqual:
                return element_string_value.compare(pattern_string_value) <= 0;
            default:
                return false;
        }
    }
    return false;
}

DataElement::DataElement() = default;

std::ostream &operator<< (std::ostream &os, const DataElement& element) {
    if (std::holds_alternative<std::string>(element.value)) {
        os << std::get<std::string>(element.value);
    } else if (std::holds_alternative<int>(element.value)) {
        os << std::get<int>(element.value);
    } else if (std::holds_alternative<double>(element.value)) {
        os << std::get<double>(element.value);
    }
    return os;
}