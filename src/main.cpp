#include <iostream>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fs = filesystem;

void printHelp();

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printHelp();
		return 1;
	}

	string desiredName = argv[1];
	fs::path currentDirectory = fs::current_path();
	bool doesDirExist = fs::exists(desiredName);
	bool isExistingDirEmpty = false;

	if (doesDirExist)
	{
		isExistingDirEmpty = fs::is_empty(desiredName);
	}

	if (doesDirExist && !isExistingDirEmpty)
	{
		printf("\033[31mDirectory already exist\033[0m\n");
		return 1;
	}

	fs::create_directory(desiredName);

	for (int i = 2; i < argc; i++)
	{
		ofstream file(currentDirectory.string() + "/" + desiredName + "/" + desiredName + "." + argv[i]);
		file.close();
	}
}

void printHelp()
{
	printf("cdf - Create Directory with Files\n");
	printf("Used to create a directory and files with desired name and extensions.\n");
	printf("\n");
	printf("Usage:\n");
	printf("cdf [name] [extensions]...");
	printf("Example:\n");
	printf("cdf chunkOfCode cpp h\n");
	printf("Creates a directory named chunkOfCode\n");
	printf("Directory contains two files; chunkOfCode.cpp and chunkOfCode.h");
}