#ifndef CREATE_FILES
#define CREATE_FILES

#include <string>
#include <unordered_map>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void createFiles();

void createFile(string extension, string fileContents);
void createFile(string extension);

void createHeaderFile();
void createSourceFile();

string generateHeaderContent(string definition);
string generateSourceContent();

#endif