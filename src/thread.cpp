/*
 * thread.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "thread.h"

DLthread::DLthread() : thread(),stop()
{
	sem_init(&stop, 0, 0);
}

DLthread::~DLthread()
{
	sem_destroy(&stop);
}

void DLthread::init()
{
	int stopValue;
	while(true)
	{
		sem_getvalue(&stop, &stopValue);
		if(stopValue != 0)
		{
			break;
		}
		this->doWork();
	}
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
	sem_post(&stop);
	pthread_join(thread, NULL);
}
