#include<iostream>
#include<cstdarg>
#include<string>
#include"dataPattern.hpp"
#include"dataPatternElement.hpp"

DataPattern::DataPattern() = default;

DataPattern::DataPattern(const char* fmt...) {
    va_list args;
    va_start(args, fmt);

    std::string format = fmt;

    for (int i = 0; i < 100 && i < format.size() && *fmt != '\0'; ++i, ++fmt) {
        std::cout << i << std::endl;
        if (*fmt == 's') {
            Condition condition = va_arg(args, Condition);
            std::string argument = va_arg(args, char*);
            values.emplace_back(condition, argument);
        } else if (*fmt == 'i') {
            values.emplace_back(va_arg(args, Condition), va_arg(args, int));
        } else if (*fmt == 'f') {
            values.emplace_back(va_arg(args, Condition), va_arg(args, double));
        }      
    }
    
    va_end(args);
}

DataPattern::DataPattern(const std::vector<DataPatternElement>& elements) {
    for (const auto & element : elements) {
        values.push_back(element);
    }
}

 const DataPatternElement& DataPattern::operator[](std::size_t idx) const { return values[idx]; }

 size_t DataPattern::size() const {return values.size();}

std::ostream &operator<< (std::ostream &os, const DataPattern& data) {
    os << "(";
    for (const auto & value : data.values) {
        os << value << ", ";
    }
    os << ")";
    return os;
}
