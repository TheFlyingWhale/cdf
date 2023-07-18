#include <iostream>
#include <fstream>
#include "utilities/utilities.hpp"
#include "unordered_map"
using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printInstructions();
		return 1;
	}

	unordered_map<string, string> valueFlags;
	unordered_map<string, bool> booleanFlags;

	string desiredName = argv[1];

	if (!proccessArguments(argc, argv, &valueFlags, &booleanFlags))
	{
		cout << "Invalid arguments provided\n\n";
		printInstructions();
		return 1;
	}

	bool verbose = booleanFlags.find("-v") != booleanFlags.end() ? true : false;

	if (verbose)
		printFlags(&valueFlags, &booleanFlags);

	if (!createDir(&desiredName, &verbose))
		return 1;

	createFiles(&desiredName, &valueFlags, &booleanFlags, &verbose);
}