#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <random>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "../LindaCommunication.h"
#include "../Pipe.h"
#include "../Logger.h"
#include "../dataGenerator.h"
#include "../request.hpp"
#include "../response.hpp"
#include "../LindaCommunication.h"

static volatile bool shouldRun;

class Client {
private:
    LindaCommunication lindaCommunication;
    Logger logger;
    time_t timeout;
public:
    Client(Pipe pipeResponse, Pipe pipeRequest, time_t timeout);
    Client(Pipe pipeResponse, Pipe pipeRequest, time_t timeout, unsigned int seed);
    ~Client();
    void run();
    void run(int generatorSizeLimits[4]);
    void run(const std::string instructionsFileName);
};

#endif