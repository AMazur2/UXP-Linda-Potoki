//
//  author: Artur Mazur
//  

#ifndef SERVER_H
#define SERVER_H

#include "Logger.h"
#include "queryList.h"
#include "Pipe.h"
#include <iostream>
#include <vector>
#include <map>


class Server
{
    private:
        Logger logger;
        QueryList list;
        std::vector<int> tuples;        // vector krotek
        Pipe requestPipe;                // potok do serwera
        std::map<pid_t, Pipe> pipes;     // potoki do klientów

    public:
        Server(const Pipe& p);           // potok wejsciowy

        ~Server();
        
        void addPipe(pid_t pid, const Pipe& pipe);

        void setPipes(std::map<pid_t, Pipe> pipes);

        void processRequest(int request);

        void processTuple(int tuple);

        void sendTuple();

};


#endif