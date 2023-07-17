#include "color.hpp"
#include <string>
using namespace std;

string green(string text)
{
	return "\033[32m" + text + "\033[0m";
}

string red(string text)
{
	return "\033[31m" + text + "\033[0m";
}