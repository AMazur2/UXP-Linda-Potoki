#include"request.hpp"

Request::Request(std::variant<Data, DataPattern> data, RequestAction requestAction, pid_t process_id, time_t timeout)
    : data{data}, action{requestAction}, pid{process_id}, timeout{timeout} {}

std::variant<Data, DataPattern> Request::get_data() {return data;}

RequestAction Request::get_action() {return action;}

pid_t Request::get_pid() {return pid;}

time_t Request::get_timeout() {return timeout;}

