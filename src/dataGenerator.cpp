//
// Created by aniela on 5/21/21.
//

#include <sstream>
#include "dataGenerator.h"

DataGenerator::DataGenerator(int max_tuple_size, int max_int, int max_real, int max_string_size) {
    gen = std::mt19937(rd());
    distrib_tuple_size = std::uniform_int_distribution<>(1, max_tuple_size);
    distrib_int = std::uniform_int_distribution<>(0, max_int);
    distrib_real = std::uniform_real_distribution<>(0, max_real);
    distrib_letter = std::uniform_int_distribution<>(static_cast<int>('a'), static_cast<int>('z'));
    distrib_string_size = std::uniform_int_distribution<>(1, max_string_size);
    distrib_condition = std::uniform_int_distribution<>(0, static_cast<int>(Condition::Count) - 1);
    distrib_type = std::uniform_int_distribution<>(0, static_cast<int>(Type::Count) - 1);
}

int DataGenerator::next_int() {
    return distrib_int(gen);
}

double DataGenerator::next_real() {
    return distrib_real(gen);
}

std::string DataGenerator::next_string() {
    int size = distrib_string_size(gen);
    std::stringstream buffer;
    for (int i = 0; i < size; i++) {
        buffer << static_cast<char>(distrib_letter(gen));
    }
    return buffer.str();
}

Condition DataGenerator::next_condition() {
    return static_cast<Condition>(distrib_condition(gen));
}

Type DataGenerator::next_type() {
    return static_cast<Type>(distrib_type(gen));
}

DataElement DataGenerator::next_data_element() {
    switch (next_type()) {
        case Type::String:
            return DataElement(next_string());
        case Type::Int:
            return DataElement(next_int());
        case Type::Real:
            return DataElement(next_real());
        default:
            return DataElement();
    }
}

DataPatternElement DataGenerator::next_data_pattern_element() {
    switch (next_type()) {
        case Type::String:
            return DataPatternElement(next_condition(), next_string());
        case Type::Int:
            return DataPatternElement(next_condition(),next_int());
        case Type::Real:
            return DataPatternElement(next_condition(),next_real());
        default:
            return DataPatternElement();
    }
}

Data DataGenerator::next_data() {
    int data_size = distrib_tuple_size(gen);
    std::vector<DataElement> elements;
    elements.reserve(data_size);
    for (int i = 0; i < data_size; i++) {
        elements.push_back(next_data_element());
    }
    return Data(elements);
}

DataPattern DataGenerator::next_data_pattern() {
    int data_size = distrib_tuple_size(gen);
    std::vector<DataPatternElement> elements;
    elements.reserve(data_size);
    for (int i =0; i < data_size; i++) {
        elements.push_back(next_data_pattern_element());
    }
    return DataPattern(elements);
}