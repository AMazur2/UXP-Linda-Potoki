#pragma once

#include<variant>
#include<ctime>
#include<sys/types.h>

#include"data.hpp"
#include"dataPattern.hpp"

enum class RequestAction {Output, Input, Read};

class Request {
    std::variant<std::monostate, Data, DataPattern> data;
    RequestAction action;
    pid_t pid;
    time_t timeout;

public:
    Request(const Data& data, RequestAction requestAction, pid_t process_id, time_t time);
    Request(const DataPattern& data_pattern, RequestAction requestAction, pid_t process_id, time_t time);

    std::variant<std::monostate, Data, DataPattern> get_data();
    RequestAction get_action();
    [[nodiscard]] pid_t get_pid() const;
    [[nodiscard]] time_t get_timeout() const;
};