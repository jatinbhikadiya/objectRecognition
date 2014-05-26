//============================================================================
// Name        : Assignment-4.cpp
// Author      : Jazz
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C, Ansi-style
//============================================================================

#include "includes.h"
#include "manager.h"


int main(int argc,char* argv[])
{
	manager m;
	m.read_data(argv,argc);
	m.train();
	return EXIT_SUCCESS;
}
