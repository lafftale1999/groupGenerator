#include "../include/groups.h"
#include "../include/utils.h"

Groups::Groups(int groupSizes, Persons persons)
{
    Groups::createGroups(groupSizes, persons);

}

void Groups::createGroups(int groupSizes, Persons persons)
{   
    int amountOfGroups = persons.getList().size() / groupSizes;
    int unevenGroupSize = persons.getList().size() % groupSizes;

    for (int i = 0; i < amountOfGroups; i++)
    {   
        vector<Person> listOfPeople;

        for (int j = 0; j < groupSizes; j++)
        {   
            int rnd = generateRandomNumber(persons.getList().size());

            listOfPeople.push_back(Person(persons.getList().at(rnd)));

            persons.removePerson(rnd);
        }

        this->addGroup(Group(listOfPeople));
    }

    int groupIndex = 0;

    while (unevenGroupSize > 0)
    {
        int rndPerson = generateRandomNumber(unevenGroupSize);
        
        this->getGroups().at(groupIndex).addMember(Person(persons.getList().at(rndPerson)));

        persons.removePerson(rndPerson);

        unevenGroupSize--;
        groupIndex++;
    }

}

void Groups::addGroup(Group group)
{
    this->groups.push_back(group);
}

vector<Group> &Groups::getGroups()
{
    return this->groups;
}