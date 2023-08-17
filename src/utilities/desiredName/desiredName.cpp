#include "desiredName.hpp"
#include "../../modules/modules.hpp"

string desiredName()
{
	ArgumentsArchive &argArc = ArgumentsArchive::getInstance();
	return argArc.find("DESIRED_NAME").it->second;
}
