// Autor: Patryk Karbownik

#include "LindaCommunication.h"

LindaCommunication::LindaCommunication(Pipe &inputPipe, Pipe &outputPipe)
{
    this->inputPipe = inputPipe;
    this->outputPipe = outputPipe;
}

int LindaCommunication::output(Request request)
{
    return send(request);
}

int LindaCommunication::input(Request request, Response &response)
{
    if(send(request) == 0)
        return receive(response, request.get_timeout());
    return -1;
}

int LindaCommunication::read(Request request, Response &response)
{
    if(send(request) == 0)
        return receive(response, request.get_timeout());
    return -1;
}

int LindaCommunication::receive(Response& r, unsigned timeout)
{
    char* buff = new char[PIPE_BUF];
    memset(buff, 0, PIPE_BUF);

    try
    {
        inputPipe.readPipe(buff, PIPE_BUF);
    }
    catch(std::runtime_error& ex)
    {
        return -1;
    }

    return -1;
}

int LindaCommunication::send(Request request)
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