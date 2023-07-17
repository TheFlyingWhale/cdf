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
		}

		if (strArg == "-s")
		{
			(*booleanFlags)["-s"] = true;
		}

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
		}
	}

	return 1;
}