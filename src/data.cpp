#include<iostream>
#include<cstdarg>
#include"data.hpp"

Data::Data() {}

Data::Data(const char* fmt...) {
    va_list args;
    va_start(args, fmt);

    std::string format = fmt;

    for (int i = 0; i < 100 && i < format.size() && *fmt != '\0'; ++i, ++fmt) {
        if (*fmt == 's') {
            values.push_back(DataElement(std::string(va_arg(args, char*))));
        } else if (*fmt == 'i') {
            values.push_back(DataElement(va_arg(args, int)));
        } else if (*fmt == 'f') {
            values.push_back(DataElement(va_arg(args, double)));
        }      
    }
    
    va_end(args);
}

const DataElement& Data::operator[](std::size_t idx) const { return values[idx]; }

bool Data::compare(DataPattern pattern) const {
    if (values.size() != pattern.size()) return false;

    for (int i = 0; i < values.size(); i++) {
        if (!values[i].compare(pattern[i])) {
            return false;
        }
    }
    return true;
}