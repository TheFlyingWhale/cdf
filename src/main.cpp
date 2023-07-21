#include "utilities/utilities.hpp"
#include "modules/modules.hpp"
#include "errors/errors.hpp"
#include "unordered_map"

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	try
	{
		if (argc < 2)
		{
			printInstructions();
			return 1;
		}

		ArgumentsArchive &aa = ArgumentsArchive::getInstance();
		string desiredName = argv[1];

		if (!proccessArguments(argc, argv))
		{
			cout << "Invalid arguments provided\n\n";
			printInstructions();
			return 1;
		}

		if (aa.exists("-v"))
			aa.printFlags();

		if (!createDir(&desiredName))
			return 1;

		createFiles(&desiredName);
	}
	catch (const exception &ex)
	{
		errorHandler(ex);
	}
}