#include "processArguments.hpp"
#include "../color/color.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int proccessArguments(int &argc, char *argv[], unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags)
{
	for (int i = 1; i < argc; i++)
	{
		if (i == 1)
		{
			if (argv[i][0] == '-')
			{
				cout << red("The first argument provided is a flag and not a valid string\n");
				return 0;
			}
		}

		string strArg = string(argv[i]);
		if (strArg == "-h")
		{
			(*booleanFlags)["-h"] = true;
		}

		if (strArg == "-s")
		{
			(*booleanFlags)["-s"] = true;
		}

		if (strArg == "-i")
		{
			(*booleanFlags)["-i"] = true;
		}

		if (strArg == "-v")
		{
			(*booleanFlags)["-v"] = true;
		}

		// If -d is provided but -h is not some error should occur
		if (strArg == "-d")
		{
			if (i + 1 >= argc)
			{
				cout << red("-d was not provided with a valid definition") << endl;
				return 0;
			}

			if (argv[i + 1][0] == '-')
			{
				cout << red("-d was followed by a flag, not a valid definition") << endl;
				return 0;
			}

			(*valueFlags)[strArg] = argv[i + 1];
		}
	}

	return 1;
}