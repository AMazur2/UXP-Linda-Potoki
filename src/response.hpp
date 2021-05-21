#pragma once

#include "data.hpp"

class Response {
    Data data;

public:
    explicit Response(Data data);

    Data get_data();
};