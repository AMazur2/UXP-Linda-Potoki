//
//  author: Artur Mazur
//  

#ifndef SERVER_H
#define SERVER_H

#include "../Logger.h"
#include "queryList.h"
#include "../Pipe.h"
#include "../data.hpp"
#include "../request.hpp"
#include "../response.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>

class Server
{
    private:
        const std::string fileName = "server" + std::to_string(getpid()) + ".log";
        Logger logger;
        QueryList list;                     // lista zapytań
        std::vector<Data> tuples;           // vector krotek
        std::map<pid_t, Pipe> inPipes;      // potok do serwera
        std::map<pid_t, Pipe> outPipes;     // potoki do klientów
        void sendResponse( Pipe p, Response r);

    public:
        Server();      

        Server(std::map<pid_t, Pipe> in, std::map<pid_t, Pipe> out);                     

        ~Server();
        
        void addInputPipe(pid_t pid, const Pipe& pipe);

        void addOutputPipe(pid_t pid, const Pipe& pipe);

        void setInputPipes(std::map<pid_t, Pipe> pipes);

        void setOutputPipes(std::map<pid_t, Pipe> pipes);

        void setPipes(std::map<pid_t, Pipe> in, std::map<pid_t, Pipe> out);

        void processInput(Request irequest);

        void processRead(Request rrequest);

        void processOutput(Request orequest);

        Pipe select(pid_t receiver);

};


#endif
