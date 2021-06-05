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

enum PipeEnd 
{
    Read = 0, Write
};

class Pipe
{
    private:

        static const int endClosed;
        int number;
        int pipeDescriptors[2];

    public:
        Pipe();

        Pipe(int key);

        Pipe(int rd, int wd);

        ~Pipe();

        void closeDescriptors();

        void closePipeEnd(PipeEnd pe);

        void writePipe(const void* buf, unsigned long len);

        bool readPipe(void* buf , unsigned long len);

        bool checkPipe(unsigned checkout);

};


#endif