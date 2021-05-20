#pragma once

#include "data.hpp"

class Response {
    Data data;

public:
    Response(Data data);

    Data get_data();
};