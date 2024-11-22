#include <iostream>
#include <fstream>
#include <string>
#include "include/persons.h"
#include "include/groups.h"
#include "include/utils.h"

using namespace std;

string readNamesFromFile();

int main()
{
    // creates a list of persons
    Persons persons = Persons(readNamesFromFile("data/names.txt"));

    // create a list of groups based on the assigned size and list of persons
    Groups groups = Groups(setGroupSize(persons.getList().size()), persons);

    // save group to file
    writeNameToFiles(groups, "data/groups.txt");
}