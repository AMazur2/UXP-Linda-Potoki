#pragma once

#include<variant>
#include<string>

class DataElement {
    std::variant<std::string, int, double> element;
};