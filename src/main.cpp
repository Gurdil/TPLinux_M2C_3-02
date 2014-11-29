//============================================================================
// Name        : TP_Linux.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "thread.h"
#include <unistd.h>
#include <iostream>
using namespace std;

int main()
{
	DLthread thread;
	thread.start();
	usleep(5000000);
	thread.join();
	return 0;
}
