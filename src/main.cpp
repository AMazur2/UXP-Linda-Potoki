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
        }
        else
        {
            inPipe.closeEnd(PipeEnd::Write);
            outPipe.closeEnd(PipeEnd::Read);
            inPipes[ret] = inPipe;
            outPipes[ret] = outPipe;
        }
    }

    Server serv(inPipes, outPipes);

    serv.run();
    //utworzenie serwera
    //oczekiwanie w petli na znak wyjsci
    int c;
    while((c = getchar()) != 'q')
    {

    }
    //Kill them All!
    return 0;
}