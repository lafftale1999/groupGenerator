#ifndef GROUPS_H
#define GROUPS_H

#include "group.h"
#include "persons.h"

class Groups
{
    private:
        vector<Group> groups;

    public:
        Groups(int groupSizes, Persons persons);

        void createGroups(int groupSizes, Persons persons);

        void addGroup(Group group);

        vector<Group> &getGroups();
};

#endif