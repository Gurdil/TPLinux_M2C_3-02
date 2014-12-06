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
 * <p>
 * 		A wraper to a pthread C thread
 * <p>
 **/
class DLthread
{
public:
	/**
	 * @fn DLthread()
	 * Constructor
	 */
	DLthread();
	virtual ~DLthread();

	/**
	 * @fn void start()
	 * this method create the thread
	 */
	void start();
	/**
	 * @fn void join()
	 *	this method join the thread
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
	 * the method to overload in a subclass
	 * the main job of the thread is do in this method
	 */
	virtual void doWork();

};

#endif /* THREAD_H_ */
