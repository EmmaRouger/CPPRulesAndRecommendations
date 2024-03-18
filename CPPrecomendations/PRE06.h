//PRE06-C. Enclose header files in an include guard
#ifndef PRE06_H // here is the guard
#define PRE06_H


#include <string>
#include <iostream>
using namespace std;
class PRE06{
    private:
    string test;
    int DOB;

    public:
    PRE06(string newTest, int newDOB);
};


#endif