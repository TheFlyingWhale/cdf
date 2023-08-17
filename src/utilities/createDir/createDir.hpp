#ifndef CREATE_DIRECTORY
#define CREATE_DIRECTORY

#include "../isVerbose/isVerbose.hpp"
#include "../color/color.hpp"
#include "../../modules/modules.hpp"
#include <exception>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void createDir();
void createDirectory();

void confirmActionValidity();
int checkIfDirExists();
void confirmDirIsEmpty();

void printExistsInfo(int doesDirExist);

#endif