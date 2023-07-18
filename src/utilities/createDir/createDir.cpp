#include "createDir.hpp"
#include "../color/color.hpp"
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int createDir(string *desiredName, bool *verbose)
{
	bool doesDirExist = fs::exists(*desiredName);
	if (*verbose)
	{
		cout << "\n";

		if (doesDirExist)
			cout << red("Directory already exists.\n");

		if (!doesDirExist)
			cout << green("Directory does not exist.\n");
	}

	bool isExistingDirEmpty = doesDirExist ? fs::is_empty(*desiredName) : false;
	if (*verbose && doesDirExist)
	{
		if (isExistingDirEmpty)
			cout << green("Existing directory is empty and will be replaced.\n");

		if (!isExistingDirEmpty)
			cout << red("Existing directory is not empty and will not be replaced\n");
	}

	if (doesDirExist && !isExistingDirEmpty)
	{
		cout << red("Could not create directory\n");
		return 0;
	}

	fs::create_directory(*desiredName);

	if (*verbose)
		cout << green("Directory created\n");

	return 1;
}