#include "isVerbose.hpp"
#include "../../modules/modules.hpp"

int isVerbose()
{
	ArgumentsArchive &argArc = ArgumentsArchive::getInstance();
	return argArc.exists("-v");
}
