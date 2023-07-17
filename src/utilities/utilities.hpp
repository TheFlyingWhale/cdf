#ifndef UTILITIES
#define UTILITIES
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

struct 

string green(string text);
string red(string text);

void handleExtension(char *extension, string &desiredName);
void logExtension(string extension);
void handleHeaderCreation(string &desiredName, string headerType);

int confirmAction(string prompt);
int confirmAction();

void createFile(string desiredName, string extension, string fileContents);
void createFile(string desiredName, string extension);

#endif