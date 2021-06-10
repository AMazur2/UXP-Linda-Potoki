#pragma once

#include "data.hpp"

class Response {
    Data data;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int version)
    {
        ar & data;
    }
public:
    explicit Response(Data data);

    Data get_data();
};