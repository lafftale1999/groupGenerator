#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <fstream>

#include "groups.h"

typedef enum {
    GENERATED,
    N_GENERATED,
    ERROR
} isGenerated;

std::string readNamesFromFile(string filePath);

void writeGroupsToFiles(Groups groups, string filePath);

isGenerated readGroupsFromFile(string filePath);

int generateRandomNumber(int max);

int printGroupsFromFile(string filePath);

#endif