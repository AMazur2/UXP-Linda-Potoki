//
// autor : Artur Mazur
// 

#ifndef PIPE_H
#define PIPE_H

#include <unistd.h>
#include <stdio.h>
#include <string>
#include <sys/param.h>
#include <semaphore.h>
#include <random>
#include <sstream>
#include <pthread.h>
#include <errno.h>
#include <cstring>
#include "Logger.h"

static int nr;

enum PipeEnd 
{
    Read = 0, Write
};

class Pipe
{
    private:
        const std::string fileName = "pipe" + std::to_string(getpid()) + "_" +  std::to_string(nr++) + ".log";
        int number;
        int pipeDescriptors[2];
        Logger logger;

    public:
        Pipe();

        Pipe(int key);

        Pipe(int rd, int wd);

        ~Pipe();

        Pipe(const Pipe& p) : logger(fileName)
        {
            this->number = p.number;
            this->pipeDescriptors[0] = p.pipeDescriptors[0];
            this->pipeDescriptors[1] = p.pipeDescriptors[1];
        }

    Pipe& operator=(const Pipe& other)
    {
        // Guard self assignment
        if (this == &other)
            return *this;

        this->number = other.number;
        this->pipeDescriptors[0] = other.pipeDescriptors[0];
        this->pipeDescriptors[1] = other.pipeDescriptors[1];


    }

        void closeDescriptors();

        void closeEnd(PipeEnd pe);

        void write_to(const void* buf, unsigned long len);

        bool read_from(void* buf , unsigned long len);

        bool readWithTimeout(void* buffer, unsigned long length, unsigned timeout);

        int returnDescriptor(int i);
};


#endif