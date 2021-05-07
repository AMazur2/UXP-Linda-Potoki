//
//  author: Artur Mazur
//  

#ifndef QUERY_H
#define QUERY_H

#include <iostream>

struct Query                            //do zmiany jak przyjdzie zapytanie
{
    int priotiry;
    // zapytanie
    char c;
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
        void showQuery();

};

#endif