#include "../include/persons.h"
#include <vector>


Persons::Persons(string stringOfNames)
{
    vector<string> names = generateNames(stringOfNames);

    for (string name : names)
    {
        addPerson(Person(name));
    }
}

vector<string> Persons::generateNames(string stringOfNames)
{
    vector<string> listOfNames;

    string temp;

    for (int i = 0; i < stringOfNames.length(); i++)
    {
        if (stringOfNames[i] != ',')
        {
            temp.push_back(stringOfNames[i]);
        }

        else 
        {
            listOfNames.push_back(temp);
            temp = "";
        }
    }

    return listOfNames;
}

void Persons::addPerson(Person person)
{
    this->list.push_back(person);
}

void Persons::removePerson(int index)
{
    this->list.erase(this->list.begin() + index);
}

vector<Person> Persons::getList()
{
    return this->list;
}