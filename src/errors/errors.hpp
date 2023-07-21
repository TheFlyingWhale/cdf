#ifndef ERROR_HANDLING
#define ERROR_HANDLING

#include <filesystem>

using namespace std;
namespace fs = filesystem;

void errorHandler(const exception &ex);

void handleFileSystemErrors(const fs::filesystem_error &fex);

#endif
