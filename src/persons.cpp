#include "../include/persons.h"
#include <vector>


Persons::Persons(string stringOfNames)
{   
    // create a list of names
    vector<string> names = generateNames(stringOfNames);

    // create a list of person 
    for (string name : names) addPerson(Person(name));
}

vector<string> Persons::generateNames(string stringOfNames)
{
    // vector to store all names in
    vector<string> listOfNames;

    // a temporary string to store the current name in
    string temp;

    // for loop to loop through the unformatted string
    for (int i = 0; i < stringOfNames.length(); i++)
    {   
        // if the character is a letter
        if (stringOfNames[i] != ',')
        {
            // add to string
            temp.push_back(stringOfNames[i]);
        }
        
        // if it's a ',' add to list and reset tempstring
        else 
        {
            listOfNames.push_back(temp);
            temp = "";
        }
    }

    // return list
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