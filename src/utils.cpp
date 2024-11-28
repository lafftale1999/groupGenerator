#include "../include/utils.h"
#include "../include/groups.h"
#include "../include/group.h"
#include "../include/person.h"
#include <vector>

using namespace std;

string readNamesFromFile(string filePath)
{
    // open stream
    ifstream File(filePath);

    // variable to store data from file
    string textFromFile;

    // checking if file was opened 
    if(!File.is_open())
    {
        cout << "The file could not be opened" << std::endl;
        return " ";
    }

    // system message and read files    
    cout << "Reading names from file: " << filePath << endl;
    getline(File, textFromFile);

    // checking that data was read correctly
    if (textFromFile.size() > 0)
    {
        cout << "File was succesfully read" << endl;
    }

    // close stream
    File.close();

    // return the file
    return textFromFile;
}

void writeGroupsToFiles(Groups groups, string filePath)
{
    // open stream
    ofstream File(filePath);

    // system message
    cout << "Writing names to file: " << filePath << endl;

    // variable for printing group numbers
    int index = 1;

    // enh for loop to write file
    for (Group group : groups.getGroups())
    {      
        File << "Group " << index++ << endl;

        for (Person person : group.getGroup())
        {
            File << " - " << person.getName() << endl;
        }

        File << endl;
    }

    // close stream
    File.close();
}

isGenerated readGroupsFromFile(string filePath)
{
    fstream File(filePath);

    // variable to store text from file in
    string textFromFile;

    // check if file exists
    if (!File.is_open())
    {
        cout << "The file could not be opened: " << filePath << endl;
        return ERROR;
    }

    // get the data from file
    getline(File, textFromFile);

    // if nothing in file
    if (textFromFile.size() <= 0)
    {
        cout << "There is no text in file: " << filePath << endl;
        return N_GENERATED;
    }

    return GENERATED;
}

int generateRandomNumber(int max)
{   
    int rnd = 0;
    rnd = rand() % max;

    return rnd;
}

int printGroupsFromFile(string filePath)
{
    fstream File(filePath);

    // variable to store text from file in
    string textFromFile;

    // check if file exists
    if (!File.is_open())
    {
        cout << "The file could not be opened: " << filePath << endl;
        return 1;
    }

    // get the data from file
    while(getline(File, textFromFile))
    {
        cout << textFromFile << endl;
    }

    return 0;
}