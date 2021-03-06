#include"request.hpp"

Request::Request(const Data& data, RequestAction requestAction, pid_t process_id, time_t time)
    : data{data}, action{requestAction}, pid{process_id}, timeout{time} {}

    this->data = boost::variant<int, Data, DataPattern>( data);
    // this->data = data;
}

Request::Request() : action{RequestAction::Input}, pid{0}, timeout{0}, data{0} {}

boost::variant<int, Data, DataPattern> Request::get_data() {return data;}

RequestAction Request::get_action() {return action;}

pid_t Request::get_pid() const {return pid;}

time_t Request::get_timeout() const {return timeout;}



Request::Request(DataPattern data_pattern, RequestAction requestAction, pid_t process_id, time_t time)
    : action{requestAction}, pid{process_id}, timeout{time} {

    this->data = boost::variant<int, Data, DataPattern>( data_pattern);
}

