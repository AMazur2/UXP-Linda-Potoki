cmake_minimum_required(VERSION 3.17)

project(UXP1A-Linda-Potoki)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(linda-potoki
    src/main.cpp
    src/Pipe.h src/Pipe.cpp
    src/dataElement.hpp src/dataElement.cpp 
    src/data.hpp src/data.cpp
    src/dataPatternElement.hpp src/dataPatternElement.cpp
    src/dataPattern.hpp src/dataPattern.cpp 
    src/response.hpp src/response.cpp 
    src/request.hpp src/request.cpp
        src/LindaCommunication.cpp src/LindaCommunication.h)

include(BoostTestHelpers.cmake)
target_link_libraries( linda-potoki -lboost_serialization )
set(DEPS src/data.cpp src/dataElement.cpp src/dataPattern.cpp)
add_boost_test(test/data_test.cpp "${DEPS}")      

set(DEPS src/dataElement.cpp src/dataPatternElement.cpp)
add_boost_test(test/dataElement_test.cpp "${DEPS}")  

set(DEPS src/dataPattern.cpp src/dataPatternElement.cpp)
add_boost_test(test/dataPattern_test.cpp "${DEPS}")  

set(DEPS src/dataPatternElement.cpp)
add_boost_test(test/dataPatternElement_test.cpp "${DEPS}")  

set(DEPS src/request.cpp src/data.cpp src/dataElement.cpp src/dataPattern.cpp)
add_boost_test(test/request_test.cpp "${DEPS}")  

set(DEPS src/response.cpp src/data.cpp src/dataElement.cpp)
add_boost_test(test/response_test.cpp "${DEPS}")  


enable_testing()