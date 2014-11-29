/*
 * puce.h
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */


#ifndef PUCE_H_
#define PUCE_H_

#include "thread.h"
#include <chrono>
#include <random>

class DLpuce: public DLthread
{
public:
	DLpuce();
	virtual ~DLpuce();

	int get_posX();
	int get_posY();
	void join();
	void go();
	int getNbrPuceWaiting();

private:
	sem_t stop;
	sem_t waitDebut;
	int posX;
	int posY;
	char display;
	int id;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution;

	static int nbPuce;
	static sem_t nbPuceWait;

protected:
	virtual void doWork();

};

#endif /* PUCE_H_ */
