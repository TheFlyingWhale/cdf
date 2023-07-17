#include "processArguments.hpp"
#include "../color/color.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int proccessArguments(int &argc, char *argv[], unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags)
{
	for (int i = 2; i < argc; i++)
	{
		string strArg = string(argv[i]);
		if (strArg == "-h")
		{
			(*booleanFlags)["-h"] = true;
			continue;
		}

		if (strArg == "-s")
		{
			(*booleanFlags)["-s"] = true;
			continue;
		}

		if (strArg == "-i")
		{
			(*booleanFlags)["-i"] = true;
			continue;
		}

		// If -d is provided but -h is not some error should occur
		if (strArg == "-d")
		{
			if (i + 1 >= argc)
			{
				cout << red("There was no valid argument after -d") << endl;
				return 0;
			}
			if (argv[i + 1][0] == '-')
			{
				cout << red("The following argument after -d was not a valid string") << endl;
				return 0;
			}

			(*valueFlags)[strArg] = argv[i + 1];

			// Iterate i and continue since the following arg has been handled
			// Find a more elegant solution?
			i++;
			continue;
		}

		// If the loop reaches this point something went wrong
		return 0;
	}

	return 1;
}