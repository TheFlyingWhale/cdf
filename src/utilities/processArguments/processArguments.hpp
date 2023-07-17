#ifndef PROCESS_ARGUMENTS
#define PROCESS_ARGUMENTS

#include <string>
using namespace std;

int proccessArguments(int &argc, char *argv[], unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags);

#endif