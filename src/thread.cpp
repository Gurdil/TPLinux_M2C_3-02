/*
 * thread.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "thread.h"

DLthread::DLthread() : thread()
{

}

DLthread::~DLthread()
{

}

void DLthread::doWork()
{
	cout << "I'm a thread !" << endl;
			usleep(1000000);
}

void DLthread::start()
{
	pthread_create(&thread, 0, &DLthread::cFonction, this);
}

void DLthread::join()
{
	pthread_join(thread, NULL);
}
