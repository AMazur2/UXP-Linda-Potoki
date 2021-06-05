#include<iostream>
#include<map>

#include"Pipe.h"
#include"client/client.h"
#include"server/Server.h"
#include"data.hpp"
#include"dataElement.hpp"
#include"dataPattern.hpp"
#include"dataPatternElement.hpp"

using namespace std;
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    //utworzenie klientow
    map<pid_t, Pipe> inPipes;
    map<pid_t, Pipe> outPipes;

    for(int i = 0; i < 2; ++i)
    {
        Pipe inPipe(i+1);
        Pipe outPipe(i+1);

        int ret;

        if((ret = fork())==0)
        {
           inPipe.closeEnd(PipeEnd::Read);
           outPipe.closeEnd(PipeEnd::Write);
           Client client(outPipe, inPipe, 2);
           client.run();
           return 0;
        }
        else
        {
            inPipe.closeEnd(PipeEnd::Write);
            outPipe.closeEnd(PipeEnd::Read);
            inPipes[ret] = inPipe;
            outPipes[ret] = outPipe;
        }
    }


    int server_pid = fork();
    if(server_pid == 0) {
        Server serv(inPipes, outPipes);
        serv.run();
        return 0;
    }
    //utworzenie serwera
    //oczekiwanie w petli na znak wyjsci
    int c;
    while(getchar() != 'q');

    for(auto &pid_descriptor : inPipes)
    {
        kill(pid_descriptor.first, SIGTERM);
        int status;
        waitpid(pid_descriptor.first, &status, 0);
    }

    if(server_pid) {
        kill(server_pid, SIGTERM);
        int status;
        waitpid(server_pid, &status, 0);
    }


    return 0;
}