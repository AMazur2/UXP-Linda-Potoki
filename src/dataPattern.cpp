#include<iostream>
#include<sstream>
#include<cstdarg>
#include<string>
#include"dataPattern.hpp"
#include"dataPatternElement.hpp"

DataPattern::DataPattern() {}

DataPattern::DataPattern(const char* fmt...) {
    va_list args;
    va_start(args, fmt);

    std::string format = fmt;

    for (int i = 0; i < 100 && i < format.size() && *fmt != '\0'; ++i, ++fmt) {
        std::cout << i << std::endl;
        if (*fmt == 's') {
            Condition condition = va_arg(args, Condition);
            std::string argument = va_arg(args, char*);
            values.push_back(DataPatternElement(condition, argument));
        } else if (*fmt == 'i') {
            values.push_back(DataPatternElement(va_arg(args, Condition), va_arg(args, int)));
        } else if (*fmt == 'f') {
            values.push_back(DataPatternElement(va_arg(args, Condition), va_arg(args, double)));
        }      
    }
    
    va_end(args);
}

DataPattern::DataPattern(const std::vector<DataPatternElement>& elements) {
    for (const auto & element : elements) {
        values.push_back(element);
    }
}

std::string DataPattern::to_string() {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

std::ostream &operator<< (std::ostream &os, const DataPattern& data) {
    os << "(";
    for (const auto & value : data.values) {
        os << value << ", ";
    }
    os << ")";
    return os;
}


// const DataPatternElement& DataPattern::operator[](std::size_t idx) const { return values[idx]; }

// int DataPattern::size() const {return values.size();}
