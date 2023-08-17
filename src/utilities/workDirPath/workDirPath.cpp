#include "workDirPath.hpp"

fs::path workDirPath()
{
	return fs::current_path();
}
