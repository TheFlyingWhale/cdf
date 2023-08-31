#include "isVerbose.hpp"
#include "../../modules/modules.hpp"

int isVerbose()
{
	ArgumentsArchive &argumentsArchive = ArgumentsArchive::getInstance();
	return argumentsArchive.exists("-v");
}
