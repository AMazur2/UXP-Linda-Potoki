//
// Author: Artur Mazur
//

#include "Server.h"

Server::Server() : logger(fileName), list()
{
}

Server::Server(std::map<pid_t, Pipe> in, std::map<pid_t, Pipe> out) : logger(fileName), list()
{
    setInputPipes(in);
    setOutputPipes(out);
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

void Server::processInput(Request &irequest)
{
    int i = 0;
    DataPattern request_pattern = boost::get<DataPattern>(irequest.get_data());
    while(i < this->tuples.size())
    {
        Data current = this->tuples[i];
        if(current.compare(request_pattern))
        {
            Response r(current);
            this->tuples.erase(this->tuples.begin()+i);
            Pipe p = select(irequest.get_pid());

            sendResponse(p, r);

            return;
        }
        i++;
    }

    Query* q = new Query(irequest, RequestAction::Input);
    
    this->list.saveQuery(q);

}

void Server::processRead(Request &rrequest)
{
    int i = 0;
    DataPattern request_pattern = boost::get<DataPattern>(rrequest.get_data());
    while(i < this->tuples.size())
    {
        Data current = this->tuples[i];
        if(current.compare(request_pattern))
        {
            Response r(this->tuples[i]);

            Pipe p = select(rrequest.get_pid());

            sendResponse(p, r);

            return;
        }
        i++;
    }

    Query* q = new Query(rrequest, RequestAction::Input);

    this->list.saveQuery(q);
}

void Server::processOutput(Request &orequest)
{
    Data new_data = boost::get<Data>(orequest.get_data());
    Query *current = this->list.head;
    while(current != nullptr)
    {
        DataPattern current_pattern = boost::get<DataPattern>((current->r).get_data());
        if(new_data.compare(current_pattern))
        {
            Response r(boost::get<Data>(orequest.get_data()));
            Pipe p = select(current->r.get_pid());

            sendResponse(p, r);

            this->list.deleteQuery(current);

            if(current->priority == RequestAction::Input)
            {
                return;
            }

        }
        current = current->nextQuery;
    }
    tuples.push_back(boost::get<Data>(orequest.get_data()));
}

Pipe Server::select(pid_t receiver)
{
    auto search = this->outPipes.find(receiver);
    return search->second;
}

void Server::sendResponse(Pipe p, Response r)
{
    std::stringstream stream;
    boost::archive::text_oarchive t_oa(stream);

    t_oa << r;
    try {
        p.write_to(stream.str().c_str(), stream.str().size());
        this->logger.write("Successfully send : " + r.get_data().to_string());
    }
    catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}
