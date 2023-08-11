#include "createDir.hpp"
#include "../color/color.hpp"
#include "../../modules/modules.hpp"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int createDir(string *desiredName)
{
	ArgumentsArchive &argArc = ArgumentsArchive::getInstance();
	int verbose = argArc.exists("-v");

	bool doesDirExist = fs::exists(*desiredName);
	if (verbose)
		printExistsInfo(doesDirExist);

	bool isExistingDirEmpty = doesDirExist ? fs::is_empty(*desiredName) : false;
	if (verbose && doesDirExist)
		printIsExistingInfo(isExistingDirEmpty);

	if (doesDirExist && !isExistingDirEmpty)
		return 0;

	try
	{
		fs::create_directory(*desiredName);
		if (verbose)
			cout << green("Directory created\n");
	}
	catch (const fs::filesystem_error &e)
	{
		cout << red("Failed to create directory\n");
		printf("Error: %s", e.what());
	}
	catch (...)
	{
		cout << red("Unknown error occurred. Failed to create directory\n");
	}

	return 1;
}

void printExistsInfo(int doesDirExist)
{
	cout << "\n";

	if (doesDirExist)
		cout << red("Directory already exists.\n");

	if (!doesDirExist)
		cout << green("Directory does not exist.\n");
}

void printIsExistingInfo(int isExistingDirEmpty)
{
	if (isExistingDirEmpty)
		cout << green("Existing directory is empty and will be replaced.\n");

	if (!isExistingDirEmpty)
	{
		cout << red("Existing directory is not empty and will not be replaced\n");
	}
}