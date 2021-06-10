#include<iostream>
#include<sstream>
#include<cstdarg>
#include"data.hpp"

Data::Data() = default;

Data::Data(const char* fmt...) {
    va_list args;
    va_start(args, fmt);

    std::string format = fmt;

    for (int i = 0; i < 100 && i < format.size() && *fmt != '\0'; ++i, ++fmt) {
        if (*fmt == 's') {
            values.emplace_back(std::string(va_arg(args, char*)));
        } else if (*fmt == 'i') {
            values.emplace_back(va_arg(args, int));
        } else if (*fmt == 'f') {
            values.emplace_back(va_arg(args, double));
        }      
    }
    
    va_end(args);
}

Data::Data(const std::vector<DataElement>& elements) {
    for (auto & element : elements) {
        values.push_back(element);
    }
}

const DataElement& Data::operator[](std::size_t idx) const { return values[idx]; }

Data::Data(const std::vector<DataElement>& elements) {
    for (auto & element : elements) {
        values.push_back(element);
    }
}

bool Data::compare(const DataPattern& pattern) const {
    if (values.size() != pattern.size()) return false;

    for (int i = 0; i < values.size(); i++) {
        if (!values[i].compare(pattern[i])) {
            return false;
        }
    }
    return true;
}


std::string Data::to_string() {
    std::stringstream ss;
    ss << *this;
    return ss.str();
}

std::ostream &operator<< (std::ostream &os, const Data& data) {
    os << "(";
    for (const auto & value : data.values) {
        os << value << ", ";
    }
    os << ")";
    return os;
}


