
#ifndef UXP1A_LINDA_POTOKI_LINDACOMMUNICATION_H
#define UXP1A_LINDA_POTOKI_LINDACOMMUNICATION_H


#include "Pipe.h"
#include "request.hpp"
#include "response.hpp"

class LindaCommunication {
private:
    Pipe inputPipe;
    Pipe outputPipe;
    int send(Request request);
    int receive(Response &response);
public:
    LindaCommunication(Pipe &inputPipe, Pipe &outputPipe);
    int output(Request request);
    int read(Request request, Response &response);
    int input(Request request, Response &response);
};


#endif //UXP1A_LINDA_POTOKI_LINDACOMMUNICATION_H
