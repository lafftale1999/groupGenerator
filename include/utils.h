#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <fstream>

#include "groups.h"

std::string readNamesFromFile(string filePath);

int generateRandomNumber(int max);

void writeNameToFiles(Groups groups, string filePath);

int setGroupSize(int peopleInList);

#endif