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
#include <iostream>

class DLControler;

/**
 * @author PHILIPPE Jean-Baptiste
 *	<p>
 * 		Represent a fleaS
 * 	<p>
 **/
class DLpuce: public DLthread
{
public:
	/**
	 * @fn DLpuce(DLControler *controler)
	 * Constructor
	 * @param controler The controller
	 */
	DLpuce(DLControler *controler);
	virtual ~DLpuce();
	/**
	 * @fn void join()
	 * the thread will be terminated
	 */
	void join();
	/**
	 * @fn void go()
	 * The flea begin a new turn
	 */
	void go();
	/**
	 * @fn static int getNbrPuceWaiting()
	 * @return the number of fleas who have finish their turn
	 */
	static int getNbrPuceWaiting();
	/**
	 * @fn static void resetPuceWaitCounter()
	 * Reset the counter of fleas who have finish their turn
	 */
	static void resetPuceWaitCounter();

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
	DLControler *controler;

protected:
	virtual void doWork();

};

#endif /* PUCE_H_ */
