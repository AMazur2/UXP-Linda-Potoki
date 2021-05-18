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

public:
    Request(std::variant<Data, DataPattern> data, RequestAction requestAction, pid_t process_id, time_t timeout);

    std::variant<Data, DataPattern> get_data();
    RequestAction get_action();
    pid_t get_pid();
    time_t get_timeout();
};