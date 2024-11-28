#ifndef GROUPS_H
#define GROUPS_H

#include "group.h"
#include "persons.h"

class Groups
{
    private:
        vector<Group> groups;

    public:
        Groups();

        void createGroups(int groupSizes, Persons persons);

        int setGroupSize(int peopleInList);

        void addGroup(Group group);

        vector<Group> &getGroups();
};

#endif