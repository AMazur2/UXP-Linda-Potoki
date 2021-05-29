//
// Author: Artur Mazur
//

#include "Server.h"
#include <stdio.h>

Server::Server()
{
    std::string filename = "seerver" + std:to_string(getpid()) + ".log";
    this->logger = new Logger(filename);
    this->list = new QueryList();
}

Server::Server(std::map<pid_t, Pipe> in, std::map<pid_t, Pipe> out)
{
    std::string filename = "seerver" + std:to_string(getpid()) + ".log";
    this->logger = new Logger(filename);
    setInputPipes(in);
    setOutputPipes(out);
    this->list = new QueryList();
}

Server::~Server()
{
    logger.close();
}

void Server::setInputPipes(std::map<pid_t, Pipe> p)
{
    this->inPipes = p;
}

void Server::setOutputPipes(std::map<pid_t, Pipe> p)
{
    this->outPipes = p;
}

void Server::addInputPipe(pid_t pid, const Pipe& pipe)
{
    this->inPipes[pid] = pipe;
}

void Server::addOutputPipe(pid_t pid, const Pipe& pipe)
{
    this->outPipes[pid] = pipe;
}

void Server::setPipes(std::map<pid_t, Pipe> in, std::map<pid_t, Pipe> out)
{
    this->inPipes = in;
    this->outPipes = out;
}

void Server::processInput(Request irequest)
{
    int i = 0;
    while(i < this->tuples.size())
    {
 /*       if(compare(ireques, this->tuples[i])
        {
            Response *r = new Response(this->tuples[i]);
            this->tuples.erase(this->tuples.begin()+i);
            sendResponse(r, ireques->get_pid());
            delete(ireques);
            return;
        }                                                   */
        i++;
    }

    Query *q = new Query;
    q->priority = RequestAction::Input;
    q->r = irequest;
    
    this->list.saveQuery(q); 
    return;
}

void Server::processRead(Request rrequest)
{
    int i = 0;
    while(i < this->tuples.size())
    {
 /*       if(compare(ireques, this->tuples[i])
        {
            Response *r = new Response(this->tuples[i]);
            sendResponse(r, rreques->get_pid());
            delete(rrequest)
            return;
        }                                                   */
        i++;
    }

    Query *q = new Query;
    q->priority = RequestAction::Input;
    q->r = rrequest;
    
    this->list.saveQuery(q); 
    return;
}

void Server::processOutput(Request orequest)
{
    Query *current = this->list.head;
    bool send = false;
    while(current != null)
    {
/*        if(compare(current->r, orequest.get_data()))
        {
            if(current->priority == RequestAction::Read)
            {
                Response *r = new Response(orequest.get_data());
                sendResponse(r, current->r.get_pid());
                this->list.deleteQuery(current);
                send = true;
            }
            else
            {
                Response *r = new Response(orequest.get_data());
                sendResponse(r, current->r.get_pid());
                this->list.deleteQuery(current);
                delete(orequesr);
                return;
            }
        }                                                   */
        current = current->nextQuery;
    }

    if(send)
    {
        delete(orequest);
        return;
    }   

    this->tuples.push_back(orequest.get_data());
}
