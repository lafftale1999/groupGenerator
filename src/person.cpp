#include "../include/person.h"
#include <iostream>

using namespace std;

// constructor
Person::Person(string n)
{   
    Person::setName(n);
}

string Person::getName()
{
    return this->name;
}

void Person::setName(string n)
{
    this->name = n;
}