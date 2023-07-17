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
	printf("cdf [name dir and files] [<file extensions>]\n");
	printf("cdf [name] [-s] [-h] [i] [-d <definition>]\n");
	printf("\n");
	printf("[name] - The name of directory and files\n\n");
	printf("[-s] - Create source file\n\n");
	printf("[-h] - Create header file\n\n");
	printf("[-i] - Include import of header in source\n\n");
	printf("[-d <definition>] ");
	// Haha this is wack, but works
	printf("Create definition in header file\n                  and include header file in source file\n");
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
		// Handle creation of header
		//  If -d is provided but -h is not some error should occur
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
		// Handle creation of source file
		if ((*booleanFlags).find("-i") != (*booleanFlags).end())
		{
			createFile(*desiredName, "cpp", generateSourceContent(*desiredName));
		}
		else
		{
			createFile(*desiredName, "cpp");
		}
	}
}