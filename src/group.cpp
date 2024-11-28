#include "../include/group.h"

// contructor
Group::Group(vector<Person> persons)
{
    for (Person person : persons) addMember(person);
}

void Group::addMember(Person person)
{
    this->members.push_back(person);
}

vector<Person> Group::getGroup()
{
    return this->members;
}