#include"request.hpp"
#include"data.hpp"
#include"dataPattern.hpp"

Request::Request(Data data, RequestAction requestAction, pid_t process_id, time_t time)
    : action{requestAction}, pid{process_id}, timeout{time} {

    this->data = data;
}

std::variant<std::monostate, Data, DataPattern> Request::get_data() {return data;}

RequestAction Request::get_action() {return action;}

pid_t Request::get_pid() {return pid;}

time_t Request::get_timeout() {return timeout;}

