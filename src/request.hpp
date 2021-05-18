#pragma once

#include<variant>
#include<ctime>
#include<sys/types.h>

class Data;
class DataPattern;

enum class RequestAction {Output, Input, Read};

class Request {
    std::variant<std::monostate, Data, DataPattern> data;
    RequestAction action;
    pid_t pid;
    time_t timeout;

public:
    Request(Data data, RequestAction requestAction, pid_t process_id, time_t time);
    Request(DataPattern data_pattern, RequestAction requestAction, pid_t process_id, time_t time);

    std::variant<std::monostate, Data, DataPattern> get_data();
    RequestAction get_action();
    pid_t get_pid();
    time_t get_timeout();
};