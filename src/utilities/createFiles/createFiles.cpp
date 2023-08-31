#include "createFiles.hpp"
#include "../color/color.hpp"
#include "../../modules/modules.hpp"
#include "../isVerbose/isVerbose.hpp"
#include "../workDirPath/workDirPath.hpp"
#include "../desiredName/desiredName.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void createFiles()
{
	ArgumentsArchive &argumentsArchive = ArgumentsArchive::getInstance();

	if (argumentsArchive.shouldIncludeHeader())
		createHeaderFile();

	if (argumentsArchive.shouldIncludeSourceFile())
		createSourceFile();
}

void createHeaderFile()
{
	ArgumentsArchive &argumentsArchive = ArgumentsArchive::getInstance();
	if (isVerbose())
		cout << "\nHeader file:\n";

	if (argumentsArchive.shouldIncludeDefinition())
	{
		createFile("hpp", createDefinitionString(argumentsArchive.getDefinition()));
		if (isVerbose())
			cout << green("Successfully created with definition.\n");
		return;
	}

	createFile("hpp");
	if (isVerbose())
		cout << green("Successfully created.\n");
}

void createSourceFile()
{
	ArgumentsArchive &argumentsArchive = ArgumentsArchive::getInstance();
	if (isVerbose())
		cout << "\nSource file:\n";

	if (argumentsArchive.shouldIncludeHeaderInSource())
	{
		createFile("cpp", createIncludeString());
		if (isVerbose())
			cout << green("Successfully created with header.\n");
		return;
	}
	
	createFile("cpp");
	if (isVerbose())
		cout << green("Successfully created.\n");
}

void createFile(string extension, string fileContents)
{
	ofstream file((workDirPath()).string() + "/" + desiredName() + "/" + desiredName() + "." + extension);
	if (isVerbose())
		cout << "Created.\n";
	file << fileContents;
	if (isVerbose())
		cout << "Contents inserted.\n";
	file.close();
	if (isVerbose())
		cout << "File closed.\n";
}

void createFile(string extension)
{
	ofstream file((workDirPath()).string() + "/" + desiredName() + "/" + desiredName() + "." + extension);
	if (isVerbose())
		cout << "Created.\n";
	file.close();
	if (isVerbose())
		cout << "File closed.\n";
}

string createDefinitionString(string definition)
{
	return "#ifndef " + definition + "\n#define " + definition + "\n\n#endif\n";
}

string createIncludeString()
{
	return "#include \"" + desiredName() + ".hpp\"\n";
}