#include "../include/groups.h"
#include "../include/utils.h"

// constructor
Groups::Groups()
{
    srand(time(0));

    Persons persons = Persons(readNamesFromFile("data/names.txt"));

    createGroups(setGroupSize(persons.getList().size()), persons);
}

void Groups::createGroups(int groupSizes, Persons persons)
{   
    // check how many groups we will make according to the size of groups
    int amountOfGroups = persons.getList().size() / groupSizes;

    // check how many people will be left outside the group by using modulus
    int unevenGroupSize = persons.getList().size() % groupSizes;

    // for loop in range of how many groups to make
    for (int i = 0; i < amountOfGroups; i++)
    {   
        // temporary list we add to the group
        vector<Person> listOfPeople;

        // for loop in range of group size
        for (int j = 0; j < groupSizes; j++)
        {   
            // generate a number
            int rnd = generateRandomNumber(persons.getList().size());
            
            // add the person to temporary list and remove it from the list of persons
            listOfPeople.push_back(Person(persons.getList().at(rnd)));
            persons.removePerson(rnd);
        }

        // create a group with the temporary list of people and add it to our list of groups
        this->addGroup(Group(listOfPeople));
    }

    // create a variable to store groupIndex
    int groupIndex = 0;

    // while we have people without an assigned group
    while (unevenGroupSize > 0)
    {
        // generate a random number
        int rndPerson = generateRandomNumber(unevenGroupSize);
        
        // add person to group based on groupIndex and remove person from list
        this->getGroups().at(groupIndex).addMember(Person(persons.getList().at(rndPerson)));
        persons.removePerson(rndPerson);
        
        // logic for while loop
        unevenGroupSize--;
        groupIndex++;
    }

}

int Groups::setGroupSize(int peopleInList)
{
    // message to user
    cout << "How big shall each group be? ";

    // variable to store user input in
    int groupSize;

    // while loop until acceptable answer is received
    while (true)
    {   
        // receive user input
        cin >> groupSize;

        // check if answer is acceptable
        if (groupSize > peopleInList && groupSize <= 0)
        {
            cout << "The groups can't be bigger than " << peopleInList << endl;
            continue;
        }

        // retorn the user input
        return groupSize;
    }
}

void Groups::addGroup(Group group)
{
    this->groups.push_back(group);
}

// the & in this is a reference instead of copy by value - which lets the user reach the "real" group.
vector<Group> &Groups::getGroups()
{
    return this->groups;
}