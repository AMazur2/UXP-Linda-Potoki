#include"request.hpp"

Request::Request(const Data& data, RequestAction requestAction, pid_t process_id, time_t time)
    : data{data}, action{requestAction}, pid{process_id}, timeout{time} {}

Request::Request(const DataPattern& data_pattern, RequestAction requestAction, pid_t process_id, time_t time)
        : data{data_pattern}, action{requestAction}, pid{process_id}, timeout{time} {}

std::variant<std::monostate, Data, DataPattern> Request::get_data() {return data;}

RequestAction Request::get_action() {return action;}

pid_t Request::get_pid() const {return pid;}

time_t Request::get_timeout() const {return timeout;}



