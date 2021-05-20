#include"response.hpp"

Response::Response(Data data) : data{data} {}
Data Response::get_data() {return data;}