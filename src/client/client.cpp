#include "client.h"

Client::Client(Pipe pipeResponse, Pipe pipeRequest, time_t timeout) : Client(pipeResponse, pipeRequest, timeout, time(NULL))
{
    shouldRun = true;
}

Client::Client(Pipe pipeResponse, Pipe pipeRequest, time_t timeout, unsigned int seed) :
lindaCommunication(pipeResponse, pipeRequest),
logger("Client" + std::to_string(getpid()) + ".log"),
timeout(timeout)
{
    srand(seed) ;
    shouldRun = true;
}



void Client::handleSignal(int sigNum) {
    if (sigNum == SIGINT) {
        //
    } else if(sigNum == SIGTERM) {
        shouldRun = false;
    }
}

void Client::run() {
    int max_tuple_size = 5;
    int max_int = 5;
    int max_real = 5;
    int max_string_size = 5;
    int generatorSizeLimits[4] = {max_tuple_size, max_int, max_real, max_string_size};
    this->run(generatorSizeLimits);
}
void Client::run(int generatorSizeLimits[4]) {
    int max_tuple_size = generatorSizeLimits[0];
    int max_int = generatorSizeLimits[1];
    int max_real = generatorSizeLimits[2];
    int max_string_size = generatorSizeLimits[3];
    DataGenerator dataGenerator = DataGenerator(max_tuple_size, max_int, max_real, max_string_size);

    signal(SIGINT, handleSignal);
    signal(SIGTERM, handleSignal);

    while (shouldRun) {
        if (rand() % 2) {
            Data dataReq = dataGenerator.next_data();
            Request request(dataReq, RequestAction::Output, getpid(), this->timeout);

            this->logger.write("Try to output data: " + dataReq.to_string());
            if (this->lindaCommunication.output(request) != -1) {
                this->logger.write("Successfully output data: " + dataReq.to_string());
            } else {
                this->logger.write("Failed to output data: " + dataReq.to_string());
            }
        } else {
            DataPattern dataReq = dataGenerator.next_data_pattern();
            if (rand() % 2) {
                Request request(dataReq, RequestAction::Read, getpid(), this->timeout);
                Data dataResp;
                Response response(dataResp);

                this->logger.write("Try to read data with dataPattern: " + dataReq.to_string());
                if (this->lindaCommunication.read(request, response) != -1) {
                    this->logger.write("Successfully read data: " + response.get_data().to_string());
                } else {
                    this->logger.write("Failed to read data");
                }
            } else {
                Request request(dataReq, RequestAction::Input, getpid(), this->timeout);
                Data dataResp;
                Response response(dataResp);

                this->logger.write("Try to input data with dataPattern: " + dataReq.to_string());
                if (this->lindaCommunication.input(request, response) != -1) {
                    this->logger.write("Successfully input data: " + response.get_data().to_string());
                } else {
                    this->logger.write("Failed to input data");
                }
            }
        }
    }
}

void Client::run(const std::string instructionsFileName) {
    std::ifstream instructionsFile(instructionsFileName);
    if (!instructionsFile.is_open()) {
        this->logger.write("Failed open file: " + instructionsFileName);
    }

    std::string instruction;
    while (getline(instructionsFile, instruction)) {
        // do instruction
    }

    instructionsFile.close();
}

Client::~Client() {
    logger.write("Client terminated");
}
