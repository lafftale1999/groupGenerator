#include <iostream>
#include <fstream>
#include <string>
#include "include/groups.h"
#include "include/utils.h"

using namespace std;

int main()
{
    isGenerated isGenerated = readGroupsFromFile("data/groups.txt");

    switch(isGenerated)
    {
        case N_GENERATED:{
            Groups groups = Groups();
            writeGroupsToFiles(groups, "data/groups.txt");
            break;
        }
            
        case GENERATED:
            printGroupsFromFile("data/groups.txt");
            break;

        default:
            cout << "Something went wrong" << endl;
    }
    
}