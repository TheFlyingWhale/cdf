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

	bool doesDirExist = fs::exists(*desiredName);
	if (argArc.exists("-v"))
	{
		cout << "\n";

		if (doesDirExist)
			cout << red("Directory already exists.\n");

		if (!doesDirExist)
			cout << green("Directory does not exist.\n");
	}

	bool isExistingDirEmpty = doesDirExist ? fs::is_empty(*desiredName) : false;
	if (argArc.exists("-v") && doesDirExist)
	{
		if (isExistingDirEmpty)
			cout << green("Existing directory is empty and will be replaced.\n");

		if (!isExistingDirEmpty)
		{
			cout << red("Existing directory is not empty and will not be replaced\n");
			return 0;
		}
	}

	try
	{
		fs::create_directory(*desiredName);
		if (argArc.exists("-v"))
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