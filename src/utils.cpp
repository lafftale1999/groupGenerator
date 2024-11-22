#include "../include/utils.h"
#include "../include/groups.h"
#include "../include/group.h"
#include "../include/person.h"
#include <vector>

using namespace std;

string readNamesFromFile(string filePath)
{
    ifstream File(filePath);

    string textFromFile;

    if(!File.is_open())
    {
        cout << "Filen kunde ej öppnas!" << std::endl;
        return " ";
    }
    
    cout << "Reading names from file: " << filePath << endl;

    std::getline(File, textFromFile);

    File.close();

    return textFromFile;
}

void writeNameToFiles(Groups groups, string filePath)
{

    ofstream File(filePath);

    cout << "Writing names to file: " << filePath << endl;

    int index = 1;

    for (Group group : groups.getGroups())
    {   
        File << "Group " << index++ << endl;

        for (Person person : group.getGroup())
        {
            File << " - " << person.getName() << endl;
        }

        File << endl;
    }

    File.close();

}

int generateRandomNumber(int max)
{
    int rnd = 0;

    srand(time(0));

    rnd = rand() % max;

    return rnd;
}

int setGroupSize(int peopleInList)
{
    cout << "How big shall each group be? ";

    int groupSize;

    while (true)
    {
        cin >> groupSize;

        if (groupSize > peopleInList && groupSize <= 0)
        {
            cout << "The groups can't be bigger than " << peopleInList << endl;
            continue;
        }

        return groupSize;
    }
    
}