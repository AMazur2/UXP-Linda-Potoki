//
// Created by aniela on 5/21/21.
//
#pragma once

#include<random>
#include "data.hpp"

enum class Type {String, Int, Real, Count};

class DataGenerator {
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen; //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> distrib_tuple_size;
    std::uniform_int_distribution<> distrib_int;
    std::uniform_real_distribution<> distrib_real;
    std::uniform_int_distribution<> distrib_letter;
    std::uniform_int_distribution<> distrib_string_size;
    std::uniform_int_distribution<> distrib_condition;
    std::uniform_int_distribution<> distrib_type;
public:
    DataGenerator(int max_tuple_size, int max_int, int max_real, int max_string_size);
    int next_int();
    double next_real();
    std::string next_string();
    Condition next_condition();
    Type next_type();


    DataElement next_data_element();
    DataPatternElement next_data_pattern_element();
    Data next_data();
    DataPattern next_data_pattern();
};