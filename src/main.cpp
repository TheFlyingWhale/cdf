#include "utilities/utilities.hpp"
#include "modules/modules.hpp"
#include "main.hpp"

#include <exception>

using namespace std;

int main(int argc, char *argv[])
{
	try
	{
		program(argc, argv);
	}

	catch (const exception &ex)
	{
		cout << red(ex.what()) << endl;
	}

	catch (...)
	{
		cout << red("Unkown and unhandled error occurred") << endl;
	}
}

void program(int argc, char *argv[])
{
	proccessArguments(argc, argv);
	createDir();
	createFiles();
}