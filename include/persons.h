#ifndef PERSONS_H
#define PERSONS_H

#include "person.h"
#include <vector>
class Persons
{
    private:
        vector<Person> list;

    public:
        Persons(string stringOfNames);

        vector<string> generateNames(string stringOfNames);

        void addPerson(Person person);

        void removePerson(int index);

        vector<Person> getList();
};

#endif