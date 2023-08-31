#include "processArguments.hpp"
#include "../color/color.hpp"
#include "../../modules/modules.hpp"
#include "../printInstructions/printInstructions.hpp"

#include <iostream>
#include <unordered_map>
#include <string>
#include <exception>

using namespace std;

void proccessArguments(int &argc, char *argv[])
{
	ArgumentsArchive &argumentsArchive = ArgumentsArchive::getInstance();

	if (argc < 2)
	{
		printInstructions();
		throw runtime_error("Invalid input, see instructions");
	}

	argumentsArchive.addFlag("DESIRED_NAME", argv[1]);

	for (int i = 1; i < argc; i++)
	{
		if (i == 1)
		{
			if (argv[i][0] == '-')
			{
				throw runtime_error("The first argument provided is a flag and not a valid string");
			}
		}

		string strArg = string(argv[i]);

		// Create header file
		if (strArg == "-h")
		{
			argumentsArchive.addFlag("-h", true);
		}

		// Create source file
		if (strArg == "-s")
		{
			argumentsArchive.addFlag("-s", true);
		}

		// Add include to source file
		if (strArg == "-i")
		{
			argumentsArchive.addFlag("-i", true);
		}

		// Verbose prints
		if (strArg == "-v")
		{
			argumentsArchive.addFlag("-v", true);
		}

		// Add definition to header file
		// If -d is provided but -h is not an error should occur FIX
		if (strArg == "-d")
		{
			if (i + 1 >= argc)
			{
				throw runtime_error("-d was not followed with a valid definition");
			}

			if (argv[i + 1][0] == '-')
			{
				throw runtime_error("-d was followed by [" + string(argv[i + 1]) + "] which is not a valid definition");
			}

			argumentsArchive.addFlag("-d", argv[i + 1]);
		}
	}

	if (argumentsArchive.exists("-v"))
		argumentsArchive.printFlags();
}