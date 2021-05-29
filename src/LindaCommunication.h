
#ifndef UXP1A_LINDA_POTOKI_LINDACOMMUNICATION_H
#define UXP1A_LINDA_POTOKI_LINDACOMMUNICATION_H


#include "Pipe.h"
#include "request.hpp"

class LindaCommunication {
private:
    Pipe inputPipe;
    Pipe outputPipe;
public:
    LindaCommunication(Pipe inputPipe, Pipe outputPipe);
    int input(Request request);
    int read(Request request);
    int output(Request request);
};


#endif //UXP1A_LINDA_POTOKI_LINDACOMMUNICATION_H
