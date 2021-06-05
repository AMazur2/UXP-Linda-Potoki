//
//  author: Artur Mazur
//  

#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include "../request.hpp"

class Query
{
public:
    Query(Request re, RequestAction ra) : r(re), priority(ra), nextQuery(nullptr){}
    Request r;
    RequestAction priority;
    Query* nextQuery;
};

class QueryList
{
    public:
        unsigned int queryListSize;         //obecny stan bufora
        Query* head;                        //wskaznik na poczatek kolejki
        Query* lastRead;                    //wskaznik na ostatnie pytanie typu read
        Query* lastInput;                   //wskaznik na ostatnie pytanie typu input

        QueryList();
        ~QueryList();
        void saveQuery(Query* q);
        void deleteQuery(struct Query* q);
};

#endif
