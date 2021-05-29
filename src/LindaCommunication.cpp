// Autor: Patryk Karbownik

#include "LindaCommunication.h"

LindaCommunication::LindaCommunication(Pipe inputPipe, Pipe outputPipe)
{
    this->inputPipe = inputPipe;
    this->outputPipe = outputPipe;
}

int LindaCommunication::input(Request request)
{
    return 0;
}

int LindaCommunication::output(Request request)
{
    std::stringstream stream;
    boost::archive::text_oarchive t_oa(stream);

    t_oa << request;
    try {
        outputPipe.writePipe(stream.str().c_str(), stream.str().size());
    }
    catch (std::exception &e) {
        return -1;
    }
    return 0;
}

int LindaCommunication::read(Request request)
{
    return 0;
}