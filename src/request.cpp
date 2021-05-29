#include"request.hpp"

Request::Request(Data data, RequestAction requestAction, pid_t process_id, time_t time)
    : action{requestAction}, pid{process_id}, timeout{time} {

    this->data = boost::variant<int, Data, DataPattern>( data);
    // this->data = data;
}

boost::variant<int, Data, DataPattern> Request::get_data() {return data;}

RequestAction Request::get_action() {return action;}

pid_t Request::get_pid() {return pid;}

time_t Request::get_timeout() {return timeout;}

