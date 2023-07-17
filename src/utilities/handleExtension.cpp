#include <iostream>
#include <string>
#include <fstream>
#include "utilities.hpp"
#include "confirmAction/confirmAction.hpp"
#include <filesystem>
using namespace std;
namespace fs = filesystem;

void handleExtension(char *extension, string &desiredName)
{
	string exAsStr = string(extension);
	logExtension(exAsStr);

	if (exAsStr == "hpp")
	{
		handleHeaderCreation(desiredName, "hpp");
		return;
	}

	createFile(desiredName, extension);
}

void logExtension(string extension)
{
	cout << "Extension to be created: " << extension << endl;
}

void handleHeaderCreation(string &desiredName, string headerType)
{
	// int insertDefinition = confirmAction("You're trying to create a " + headerType + " file.\nDo you wish to insert definitions?");
	int insertDefinition = confirmAction();
	if (!insertDefinition)
	{
		createFile(desiredName, "hpp");
		return;
	}
	cout << "Provide definition:" << endl;
	string definition = "";
	getline(cin, definition);
	if (definition.empty())
	{
		cout << red("Provided definition is empty") << endl;
		return;
	}
	string fileContents = "#ifndef " + definition + "\n#define " + definition + "\n\n#endif\n";
	createFile(desiredName, "hpp", fileContents);
}