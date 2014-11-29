//============================================================================
// Name        : TP_Linux.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "puce.h"
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	puce thread;
	thread.start();
	usleep(5000000);
	thread.join();
	return 0;
}
