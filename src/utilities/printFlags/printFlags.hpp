#ifndef PRINT_UNORDERED_MAP
#define PRINT_UNORDERED_MAP

#include <iostream>
#include <unordered_map>
using namespace std;

void printFlags(unordered_map<string, string> *valueFlags, unordered_map<string, bool> *booleanFlags);

template <typename KeyType, typename ValueType>
void printMap(string title, unordered_map<KeyType, ValueType> *map)
{
	cout << title << ": " << endl;
	for (const auto &pair : *map)
	{
		cout << "\tKey:[" << pair.first << "] Value: [" << pair.second << "]\n";
	}
}

#endif