//
//  author: Artur Mazur
//  

#include "queryList.h"

int main()
{
    QueryList* ql = new QueryList();
    Query* q1 = new Query;
    Query* q2 = new Query;
    Query* q3 = new Query;
    Query* q4 = new Query;
    Query* q5 = new Query;
    Query* q6 = new Query;

    q1->c = 'a';
    q1->priotiry = 0;

    q2->c = 'b';
    q2->priotiry = 1;

    q3->c = 'c';
    q3->priotiry = 0;

    q4->c = 'd';
    q4->priotiry = 1;

    q5->c = 'e';
    q5->priotiry = 1;

    q6->c = 'f';
    q6->priotiry = 0;


    ql->saveQuery(q1);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->deleteQuery(q1);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->saveQuery(q2);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->saveQuery(q3);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->deleteQuery(q2);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->saveQuery(q5);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->saveQuery(q6);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->deleteQuery(q5);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->saveQuery(q4);
    //ql->showQuery();
    std::cout<< "-----------------------------" << std::endl;
    ql->deleteQuery(q4);
    //ql->showQuery();      

    delete q3;
    delete q6;
    //delete ql;

    return 0;
}