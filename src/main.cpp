#include <iostream>
#include <filesystem>
#include <fstream>
#include <variant>
#include "utilities/utilities.hpp"
using namespace std;
namespace fs = filesystem;

void printHelp();
int isItSafeToCreate(string desiredName);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printHelp();
		return 1;
	}

	string desiredName = argv[1];
	fs::path currentDirectory = fs::current_path();
	bool isSafe = isItSafeToCreate(desiredName);

	if (!isSafe)
		return 1;

	unordered_map<string, bool> flags;
	unordered_map<string, string> flagsData;

	fs::create_directory(desiredName);

	for (int i = 2; i < argc; i++)
	{
		handleExtension(argv[i], desiredName);
	}
}

void printHelp()
{
	printf("cdf - Create Directory with Files\n");
	printf("\n");
	printf("usage: cdf [name dir and files] [<file extensions>]\n");
	printf("\n");
	printf("example: cdf someCode cpp h\n");
	printf("Create a directory named 'someCode' which contains 'someCode.cpp' and 'someCode.h'\n");
}

int isItSafeToCreate(string desiredName)
{
	bool doesDirExist = filesystem::exists(desiredName);
	bool isExistingDirEmpty = doesDirExist ? filesystem::is_empty(desiredName) : false;

	if (doesDirExist && !isExistingDirEmpty)
	{
		printf("\033[31mDirectory already exist\033[0\n");
		return 0;
	}

	return 1;
}