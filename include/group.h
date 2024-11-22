#ifndef GROUP_H
#define GROUP_H

#include "../include/person.h"
#include <vector>

class Group 
{
    private:
        vector<Person> members;

    public:
        Group(vector<Person> persons);

        void addMember(Person person);

        vector<Person> getGroup();
};

#endif