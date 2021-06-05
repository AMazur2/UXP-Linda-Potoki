//
// Author: Artur Mazur
//

#include "Server.h"
#include <stdio.h>

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
    this->logger.write("Trying input: " + boost::get<DataPattern>(irequest.get_data()).to_string());
    DataPattern request_pattern = boost::get<DataPattern>(irequest.get_data());
    while(i < this->tuples.size())
    {
        Data current = this->tuples[i];
        if(current.compare(request_pattern))
        {
            Response r(current);
            this->tuples.erase(this->tuples.begin()+i);
            Pipe p = selectPipe(irequest.get_pid());

            this->logger.write("Input accepted: " + boost::get<DataPattern>(irequest.get_data()).to_string());

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
    this->logger.write("Trying Read : " + request_pattern.to_string());
    while(i < this->tuples.size())
    {
        Data current = this->tuples[i];
        if(current.compare(request_pattern))
        {
            Response r(this->tuples[i]);

            Pipe p = selectPipe(rrequest.get_pid());

            this->logger.write("Read accepted : " + request_pattern.to_string());

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
    this->logger.write("Trying Output: " + new_data.to_string());
    Query *current = this->list.head;
    while(current != nullptr)
    {
        DataPattern current_pattern = boost::get<DataPattern>((current->r).get_data());
        if(new_data.compare(current_pattern))
        {
            Response r(boost::get<Data>(orequest.get_data()));
            Pipe p = selectPipe(current->r.get_pid());

            sendResponse(p, r);
            this->logger.write("Output Accepted: " + new_data.to_string());
            this->list.deleteQuery(current);

            if(current->priority == RequestAction::Input)
            {
                return;
            }

        }
        current = current->nextQuery;
    }
    this->logger.write("Output accepted: " + new_data.to_string());
    tuples.push_back(boost::get<Data>(orequest.get_data()));
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

Pipe Server::selectPipe(pid_t receiver)
{
    auto search = this->outPipes.find(receiver);
    return search->second;
}

void Server::run()
{

    std::map<pid_t, Pipe> in = getInPipes();

    while(true)
    {
        signal(SIGINT, handleSignal);
        signal(SIGTERM, handleSignal);

        fd_set fds;
        int maxfd = 0;

        FD_ZERO(&fds);
        for(auto &x : in)
        {
            int desc = x.second.returnDescriptor(0);
            FD_SET(desc, &fds);
            if(desc > maxfd)
                maxfd = desc;
        }

        int retVal = select(maxfd +1, &fds, NULL, NULL, NULL);

        if(retVal > 0)
        {
            for (auto &x : inPipes)
            {
                if (FD_ISSET(x.second.returnDescriptor(0), &fds))
                {
                    try
                    {
                        char* buff = new char[PIPE_BUF];

                        Request r;

                        if (x.second.read_from(buff, PIPE_BUF))
                        {
                            std::stringstream inputStream;
                            inputStream << buff;

                            boost::archive::text_iarchive ia(inputStream);

                            ia >> r;

                            if(r.get_action() == RequestAction::Input) {
                                processInput(r);
                            }
                            else if(r.get_action() == RequestAction::Output) {
                                processOutput(r);
                            }
                            else {
                                processRead(r);
                            }

                        }
                    }
                    catch(std::exception& ex)
                    {
                        return;
                    }
                }
            }
        }
    }
}

void Server::handleSignal(int sigNum) {
    if (sigNum == SIGINT) {
        //
    } else if(sigNum == SIGTERM) {
        serverRun = false;
    }
}