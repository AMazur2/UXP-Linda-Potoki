#include <limits.h>
#include <stdexcept>
#include "Pipe.h"

#define CLOSED 0

Pipe::Pipe() { }

Pipe::Pipe(int key)
{
    number = key;
    if(pipe(pipeDescriptors) == -1)
        throw std::runtime_error("Failed to open pipe");
}

Pipe::Pipe(int rd, int wd)
{
    pipeDescriptors[PipeEnd::Read] = rd;
    pipeDescriptors[PipeEnd::Write] = wd;
}

Pipe::~Pipe() {}

void Pipe::closeDescriptors()
{
    closeEnd(PipeEnd::Read);
    closeEnd(PipeEnd::Write);
}

void Pipe::closeEnd(PipeEnd pe)
{
    if(pipeDescriptors[pe] != CLOSED)
    {
        close(pipeDescriptors[pe]);
        pipeDescriptors[pe] = CLOSED;
    }
}

void Pipe::write_to(const void* buffer, unsigned long length)
{
    if(pipeDescriptors[PipeEnd::Write] != CLOSED)
    {
        if(length > PIPE_BUF)
            throw std::runtime_error("Too big message: " + std::to_string(length));

        if(write(pipeDescriptors[PipeEnd::Write], buffer, length) == -1)
            throw std::runtime_error(std::strerror(errno));
    }
    else
        throw std::runtime_error("Cannot write to closed write_to end");

}

bool Pipe::read_from(void* buffer, unsigned long length)
{
    if(pipeDescriptors[PipeEnd::Read] != CLOSED)
    {
        if(read(pipeDescriptors[PipeEnd::Read], buffer, length) == -1)
            throw std::runtime_error("Error at reading pipe");

        return true;
    }
    else 
        throw std::runtime_error("Cannot read from closed read_from end");
}

bool Pipe::readWithTimeout(void* buffer, unsigned long length, unsigned timeout)
{
    struct timeval tv;
    tv.tv_sec = timeout;

    fd_set rfds;

    FD_ZERO(&rfds);
    FD_SET(pipeDescriptors[PipeEnd::Read], &rfds);

    int ret = select(pipeDescriptors[PipeEnd::Read]+1, &rfds, nullptr, nullptr, &tv);

    if(ret == -1)
        throw std::runtime_error("Error");
    else if(ret == 0)
    {
        return false;   // timeout
    }
    read_from(buffer, length);
    return true;
}

int Pipe::returnDescriptor(int i){ return pipeDescriptors[i]; }