#include"dataElement.hpp"

DataElement::DataElement(std::variant<std::string, int, double> s) : value{s} {}
std::variant<std::string, int, double> DataElement::get_value() {return value;}
