/*
 * thread.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */
#include "pthread.h"

#ifndef THREAD_H_
#define THREAD_H_

class DLthread
{
public:
	DLthread(void * argument);
	virtual ~DLthread();

	void start_thread();
	void stop_thread();
	virtual void * run(void *)=0;

private:
	pthread_t thread;
	void * argument;

};

#endif /* THREAD_H_ */
