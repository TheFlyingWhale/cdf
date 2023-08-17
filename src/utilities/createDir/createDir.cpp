#include "createDir.hpp"
#include "../desiredName/desiredName.hpp"

using namespace std;
namespace fs = filesystem;

void createDir()
{
	confirmActionValidity();
	createDirectory();
}

void createDirectory()
{
	fs::create_directory(desiredName());
	if (isVerbose())
		cout << green("Directory created\n");
}

void confirmActionValidity()
{
	bool doesDirExist = checkIfDirExists();
	if (!doesDirExist)
		return;

	confirmDirIsEmpty();
}

int checkIfDirExists()
{
	bool exists = fs::exists(desiredName());
	if (isVerbose())
		printExistsInfo(exists);

	return exists;
}

void confirmDirIsEmpty()
{
	bool isEmpty = fs::is_empty(desiredName());
	if (!isEmpty)
		throw runtime_error("Existing directory is not empty and will not be replaced");

	if (isVerbose())
		cout << green("Existing directory is empty and will be replaced.") << endl;
}

void printExistsInfo(int doesDirExist)
{
	cout << "\n";

	if (doesDirExist)
		cout << red("Directory already exists.\n");

	if (!doesDirExist)
		cout << green("Directory does not exist.\n");
}