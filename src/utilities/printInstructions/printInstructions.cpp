#include "printInstructions.hpp"
#include <iostream>

using namespace std;

void printInstructions()
{
	printf("cdf - Create Directory with Files\n");
	printf("cdf [name] [-s] [-h] [i] [-v] [-d <definition>]\n");
	printf("\n");
	printf("[name] - The name of directory and files\n");
	printf("[-v] - Verbose\n");
	printf("[-s] - Create source file\n");
	printf("[-h] - Create header file\n");
	printf("[-i] - Include import of header in source\n");
	printf("[-d <definition>] - Include provided definition in header");
}