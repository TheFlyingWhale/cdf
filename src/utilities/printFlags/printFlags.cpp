#include "printFlags.hpp"
#include <unordered_map>

void printFlags(unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags)
{
	cout << "Registered flags:\n";
	printMap("Valued", valueFlags);
	printMap("Boolean", booleanFlags);
}