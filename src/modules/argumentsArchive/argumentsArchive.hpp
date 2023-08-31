#ifndef DATA_BASE
#define DATA_BASE

#include <iostream>
#include <string>
#include <unordered_map>
#include <typeinfo>

using namespace std;

class ArgumentsArchive
{
private:
	ArgumentsArchive() {}

	~ArgumentsArchive() {}

	static ArgumentsArchive *instance;

	unordered_map<string, string> valuedFlags;
	unordered_map<string, bool> booleanFlags;

	struct FindValue
	{
		unordered_map<string, string>::iterator it;
		bool found;
	};

	template <typename KeyType, typename ValueType>
	void printMap(unordered_map<KeyType, ValueType> map, string title = "")
	{
		if (!title.empty())
		{
			cout << title << ": " << endl;
		}
		for (const auto &pair : map)
		{
			cout << "Key:[" << pair.first << "] Value: [" << pair.second << "]\n";
		}
	}

public:
	static ArgumentsArchive &getInstance()
	{
		if (!instance)
			instance = new ArgumentsArchive();

		return *instance;
	}

	void addFlag(string key, string value)
	{
		valuedFlags[key] = value;
	}

	void addFlag(string key, int value)
	{
		booleanFlags[key] = value;
	}

	bool exists(string key)
	{
		if (valuedFlags.find(key) != valuedFlags.end())
			return true;
		if (booleanFlags.find(key) != booleanFlags.end())
			return true;

		return false;
	}

	FindValue find(string key)
	{
		auto it = valuedFlags.find(key);
		return {it, it != valuedFlags.end()};
	}

	string getDefinition()
	{
		FindValue definition = find("-d");
		if (!definition.found)
			throw runtime_error("Could not find definition");

		return definition.it->second;
	}

	bool shouldIncludeDefinition()
	{
		return exists("-d");
	}

	bool shouldIncludeHeader()
	{
		return exists("-h");
	}

	bool shouldIncludeSourceFile()
	{
		return exists("-s");
	}

	bool shouldIncludeHeaderInSource()
	{
		return exists("-i");
	}

	void printFlags()
	{
		cout << "Registered flags:\n";
		printMap(valuedFlags);
		printMap(booleanFlags);
	}
};

#endif
