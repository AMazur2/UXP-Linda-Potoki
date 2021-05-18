#include"dataElement.hpp"
#include"dataPatternElement.hpp"

DataElement::DataElement(std::variant<std::string, int, double> s) : value{s} {}
std::variant<std::string, int, double> DataElement::get_value() {return value;}

bool DataElement::compare(DataPatternElement pattern_element) const {
    if (std::holds_alternative<int>(value) && std::holds_alternative<int>(pattern_element.get_value()) 
    || std::holds_alternative<int>(value) && std::holds_alternative<int>(pattern_element.get_value()) 
    || (std::holds_alternative<std::string>(value) && std::holds_alternative<std::string>(pattern_element.get_value()))) {
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
    } 
    // else if (std::holds_alternative<std::string>(value) 
    // && std::holds_alternative<std::string>(pattern_element.get_value()) {
    //     switch(pattern_element.get_condition()) {
    //         case Condition::All:
    //             return true;
    //         case Condition::Equal:
    //             return value == pattern_element.get_value();
    //         case Condition::Greater:
    //             return value > pattern_element.get_value();
    //         case Condition::GreaterEqual:
    //             return value >= pattern_element.get_value();
    //         case Condition::Less:
    //             return value < pattern_element.get_value();      
    //         case Condition::LessEqual:
    //             return value <= pattern_element.get_value();
    //         default:
    //             return false;
    //     }
    // }
    
}