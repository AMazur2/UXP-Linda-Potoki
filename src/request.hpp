#pragma once

#include<ctime>
#include<sys/types.h>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include"data.hpp"
#include"dataPattern.hpp"
#include <boost/serialization/variant.hpp>

enum class RequestAction {Output, Input, Read};

class Request {
    boost::variant<int, Data, DataPattern> data;
    RequestAction action;
    pid_t pid;
    time_t timeout;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & data;
        ar & action;
        ar & pid;
        ar & timeout;
    }

public:
    Request();
    Request(Data data, RequestAction requestAction, pid_t process_id, time_t time);
    Request(DataPattern data_pattern, RequestAction requestAction, pid_t process_id, time_t time);

    boost::variant<int, Data, DataPattern> get_data();
    RequestAction get_action();
    pid_t get_pid();
    time_t get_timeout();
};