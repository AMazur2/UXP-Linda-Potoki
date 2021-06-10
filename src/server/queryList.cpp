//
//  author: Artur Mazur
//  

#include "queryList.h"

QueryList::QueryList()
{
    this->head = nullptr;
    this->lastInput = nullptr;
    this->lastRead = nullptr;
    this->queryListSize = 0;
}

QueryList::~QueryList()
{
    Query *delete_q, *q;
    q = head;
    while(q)
    {
        delete_q = q;
        q = q->nextQuery;
        delete delete_q;
    }

    head = lastInput = lastRead = nullptr;
    queryListSize = 0;

}

void QueryList::saveQuery(Query* q)
{
    queryListSize++;

    if(head == nullptr)
    {
        head = q;
        if(q->priority == RequestAction::Read)
            lastRead = q;
        else
            lastInput = q;
    }
    else if(q->priority == RequestAction::Read)
    {
        if(lastRead == nullptr)
        {
            q->nextQuery = head;
            head = q;
        }
        else
        {
            if(lastRead->nextQuery != nullptr)
                q->nextQuery = lastRead->nextQuery;
            else
                q->nextQuery = nullptr;
            lastRead->nextQuery = q;
        }
        lastRead = q;
    }
    else
    {
        if(lastInput == nullptr)
            lastRead->nextQuery = q;
        else
            lastInput->nextQuery = q;
        lastInput = q;
    }

}

void QueryList::deleteQuery(Query* q)
{
    if(queryListSize > 0)
    {
        queryListSize--;

        if(head == q)
        {
            if(q->priority == RequestAction::Read)
            {
                if(q == lastRead)
                {
                    if(q->nextQuery != nullptr)
                        head = q->nextQuery;
                    else
                        head = nullptr;

                    lastRead = nullptr;
                }
                else
                    head = q->nextQuery;
                
            }
            else
            {
                if(q == lastInput)
                {
                    head = nullptr;
                    lastInput = nullptr;
                }
                else
                    head = q->nextQuery;
            }
        }
        else
        {
            Query* current = head;
            while( current->nextQuery != q ) 
                current = current->nextQuery;
            
            if( q == lastRead )
                lastRead = current;
            else if( q == lastInput )
            {
                if(current->priority == RequestAction::Input)
                    lastInput = current;
                else
                    lastInput = nullptr;
            }

            if(q->nextQuery != nullptr)
                current->nextQuery = q->nextQuery;
            else 
                current->nextQuery = nullptr;
        }

        delete q;
    }
}