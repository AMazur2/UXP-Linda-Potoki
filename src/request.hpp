#pragma once

#include<variant>

#include"data.hpp"
#include"dataPattern.hpp"

enum class RequestAction {Output, Input, Read};

class Request {
    std::variant<Data, DataPattern> data;
    RequestAction action;
    pid_t pid;
    time_t timeout;
};