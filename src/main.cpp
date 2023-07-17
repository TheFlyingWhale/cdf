#include <iostream>
#include <filesystem>
#include <fstream>
#include <variant>
#include "utilities/utilities.hpp"
#include "unordered_map"
using namespace std;
namespace fs = filesystem;

void printHelp();
int isItSafeToCreate(string desiredName);
void createFiles(string *desiredName, unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags);

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

	unordered_map<string, string> valueFlags;
	unordered_map<string, bool> booleanFlags;

	if (!proccessArguments(argc, argv, &valueFlags, &booleanFlags))
	{
		cout << red("processFlags failed") << endl;
		return 1;
	}

	printMap("Value flags:", valueFlags);
	printf("\n");
	printMap("Boolean flags", booleanFlags);

	fs::create_directory(desiredName);

	createFiles(&desiredName, &valueFlags, &booleanFlags);
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

string generateHeaderContent(string definition)
{
	return "#ifndef " + definition + "\n#define " + definition + "\n\n#endif";
}

string generateSourceContent(string desiredName)
{
	return "#include <" + desiredName + ".hpp>\n";
}

void createFiles(string *desiredName, unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags)
{
	if ((*booleanFlags).find("-h") != (*booleanFlags).end())
	{
		if (auto definition = (*valueFlags).find("-d"); definition != (*valueFlags).end())
		{
			createFile(*desiredName, "hpp", generateHeaderContent(definition->second));
		}
		else
		{
			createFile(*desiredName, "hpp");
		}
	}

	if ((*booleanFlags).find("-s") != (*booleanFlags).end())
	{
		if (auto definition = (*valueFlags).find("-d"); definition != (*valueFlags).end())
		{
			createFile(*desiredName, "cpp", generateSourceContent(*desiredName));
		}
		else
		{
			createFile(*desiredName, "cpp");
		}
	}
}