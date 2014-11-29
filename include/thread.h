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


	static void* cFonction(void *obj)
	{
		((DLthread*)obj)->doWork();
		return NULL;
	}

protected:

	virtual void doWork();

};

#endif /* THREAD_H_ */
