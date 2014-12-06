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

/**
 * @author PHILIPPE Jean-Baptiste
 *
 **/
class DLthread
{
public:
	DLthread();
	virtual ~DLthread();

	/**
	 * @fn void start()
	 *
	 */
	void start();
	/**
	 * @fn void join()
	 *
	 */
	void join();

private:
	pthread_t thread;


	static void* cFonction(void *obj)
	{
		((DLthread*)obj)->doWork();
		return NULL;
	}

protected:

	/**
	 * @fn virtual void doWork()
	 *
	 */
	virtual void doWork();

};

#endif /* THREAD_H_ */
