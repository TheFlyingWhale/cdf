#ifndef CREATE_FILES
#define CREATE_FILES

#include <string>
#include <unordered_map>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void createFiles(string *desiredName);

void createFile(string *desiredName, string extension, string fileContents, fs::path *workingDirectory);
void createFile(string *desiredName, string extension, fs::path *workingDirectory);

void createHeaderFile(string *desiredName);
void createSourceFile(string *desiredName);

string generateHeaderContent(string definition);
string generateSourceContent(string desiredName);

#endif