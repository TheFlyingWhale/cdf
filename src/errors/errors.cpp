#include "errors.hpp"
#include "../utilities/utilities.hpp"

#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void errorHandler(const exception &ex)
{
	if (const fs::filesystem_error *fex = dynamic_cast<const fs::filesystem_error *>(&ex))
	{
		handleFileSystemErrors(*fex);
		return;
	}

	cout << red("Unkown error occurred\n");
	cout << "This is a generic catch and should be rewritten for propper handling\n";
	cout << "Error: " << ex.what();
}

void handleFileSystemErrors(const fs::filesystem_error &fex)
{
	cout << red("Filesystem error occurred\n");
	cout << "This is a generic filesystem catch and should be rewritten for propper handling\n";
	cout << "Error: " << fex.what();
	return;
}
