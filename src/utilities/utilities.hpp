#ifndef UTILITIES
#define UTILITIES

#include <iostream>
#include <filesystem>
#include <string>
#include "confirmAction/confirmAction.hpp"
#include "processArguments/processArguments.hpp"
#include "printMap/printMap.hpp"

using namespace std;
namespace fs = filesystem;

string green(string text);
string red(string text);

void handleExtension(char *extension, string &desiredName);
void logExtension(string extension);
void handleHeaderCreation(string &desiredName, string headerType);

void createFile(string desiredName, string extension, string fileContents);
void createFile(string desiredName, string extension);

#endif