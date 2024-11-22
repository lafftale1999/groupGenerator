#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person
{
    private:
        string name;

    
    public:
        Person(string n);

        string getName();

        void setName(string n);
};

#endif