#include "desiredName.hpp"
#include "../../modules/modules.hpp"

string desiredName()
{
	ArgumentsArchive &argumentsArchive = ArgumentsArchive::getInstance();
	return argumentsArchive.find("DESIRED_NAME").it->second;
}
