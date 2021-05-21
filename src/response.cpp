#include"response.hpp"

#include <utility>

Response::Response(Data data) : data{std::move(data)} {}
Data Response::get_data() {return data;}