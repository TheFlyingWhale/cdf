#include "createFiles.hpp"
#include "../color/color.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void createFiles(string *desiredName, unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags, bool *verbose)
{
	fs::path workingDirectory = fs::current_path();

	if ((*booleanFlags).find("-h") != (*booleanFlags).end())
	{
		if (*verbose)
			cout << "\nHeader file:\n";

		if (auto definition = (*valueFlags).find("-d"); definition != (*valueFlags).end())
		{
			createFile(desiredName, "hpp", generateHeaderContent(definition->second), &workingDirectory, verbose);
			if (*verbose)

				cout << green("Successfully created with definition.\n");
		}
		else
		{
			createFile(desiredName, "hpp", &workingDirectory, verbose);
			if (*verbose)
				cout << green("Successfully created.\n");
		}
	}

	if ((*booleanFlags).find("-s") != (*booleanFlags).end())
	{
		if (*verbose)
			cout << "\nSource file:\n";

		// Handle creation of source file
		if ((*booleanFlags).find("-i") != (*booleanFlags).end())
		{
			createFile(desiredName, "cpp", generateSourceContent(*desiredName), &workingDirectory, verbose);
			if (*verbose)
				cout << green("Successfully created with header.\n");
		}
		else
		{
			createFile(desiredName, "cpp", &workingDirectory, verbose);
			if (*verbose)
				cout << green("Successfully created.\n");
		}
	}
}

void createFile(string *desiredName, string extension, string fileContents, fs::path *workingDirectory, bool *verbose)
{
	ofstream file((*workingDirectory).string() + "/" + *desiredName + "/" + *desiredName + "." + extension);
	if (*verbose)
		cout << "Created.\n";

	file << fileContents;
	if (*verbose)
		cout << "Contents inserted.\n";

	file.close();
	if (*verbose)
		cout << "File closed.\n";
}

void createFile(string *desiredName, string extension, fs::path *workingDirectory, bool *verbose)
{
	ofstream file((*workingDirectory).string() + "/" + *desiredName + "/" + *desiredName + "." + extension);
	if (*verbose)
		cout << "Created.\n";

	file.close();
	if (*verbose)
		cout << "File closed.\n";
}

string generateHeaderContent(string definition)
{
	return "#ifndef " + definition + "\n#define " + definition + "\n\n#endif";
}

string generateSourceContent(string desiredName)
{
	return "#include <" + desiredName + ".hpp>\n";
}