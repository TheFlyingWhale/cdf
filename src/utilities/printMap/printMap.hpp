#ifndef PRINT_UNORDERED_MAP
#define PRINT_UNORDERED_MAP

#include <iostream>
#include <unordered_map>
using namespace std;

template <typename KeyType, typename ValueType>
void printMap(string title, unordered_map<KeyType, ValueType> &map)
{
	cout << title << endl;
	for (const auto &pair : map)
	{
		cout << "Key:[" << pair.first << "] Value: [" << pair.second << "]\n";
	}
}

#endif