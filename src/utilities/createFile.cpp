#include "utilities.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fs = filesystem;

void createFile(string desiredName, string extension, string fileContents)
{
	fs::path currentDirectory = fs::current_path();
	ofstream file(currentDirectory.string() + "/" + desiredName + "/" + desiredName + "." + extension);
	file << fileContents;
	file.close();
}

void createFile(string desiredName, string extension)
{
	fs::path currentDirectory = fs::current_path();
	ofstream file(currentDirectory.string() + "/" + desiredName + "/" + desiredName + "." + extension);
	file.close();
}