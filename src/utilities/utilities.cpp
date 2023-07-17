#include "utilities.hpp"
#include <iostream>
#include <string>
using namespace std;
// Create functionality here and determine if it is worth its own files

string green(string text)
{
	return "\033[32m" + text + "\033[0m";
}

string red(string text)
{
	return "\033[31m" + text + "\033[0m";
}