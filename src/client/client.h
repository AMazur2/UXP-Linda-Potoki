#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <random>
#include <time.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>

#include "../LindaCommunication.h"
#include "../Pipe.h"
#include "../Logger.h"
#include "../dataGenerator.h"
#include "../request.hpp"
#include "../response.hpp"
#include "../LindaCommunication.h"

class Client {
private:
    LindaCommunication lindaCommunication;
    Logger logger;
    time_t timeout;
public:
    Client(Pipe pipeResponse, Pipe pipeRequest, time_t timeout);
    Client(Pipe pipeResponse, Pipe pipeRequest, time_t timeout, unsigned int seed);
    void start();
    void start(int generatorSizeLimits[4]);
    void start(const std::string instructionsFileName);
};

#endif