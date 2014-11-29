/*
 * thread.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */


#ifndef THREAD_H_
#define THREAD_H_

#include "pthread.h"
#include <unistd.h>
#include <semaphore.h>
#include <iostream>
using namespace std;

class DLthread
{
public:
	DLthread();
	virtual ~DLthread();

	void start();
	void join();

private:
	pthread_t thread;
	sem_t stop;

	static void* cFonction(void *obj)
	{
		((DLthread*)obj)->init();
		return NULL;
	}

	void init();

protected:

	virtual void doWork();

};

#endif /* THREAD_H_ */
