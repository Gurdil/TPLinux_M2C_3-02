/*
 * puce.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "puce.h"

int DLpuce::nbPuce = 0;
sem_t DLpuce::nbPuceWait;

DLpuce::DLpuce() :
		DLthread(),
		stop(),
		generator(std::chrono::system_clock::now().time_since_epoch().count()),
		distribution(-3,3)
{
	DLpuce::nbPuce++;
	this->id = DLpuce::nbPuce;
	sem_init(&stop, 0, 0);
	sem_init(&waitDebut, 0, 0);
	sem_init(&DLpuce::nbPuceWait, 0, 0);
	posX = 0;
	posY = 0;
	display = 'P';
}

DLpuce::~DLpuce()
{
	sem_destroy(&stop);
}

void DLpuce::doWork()
{
	int stopValue;
	while(true)
	{
		sem_getvalue(&stop, &stopValue);
		if(stopValue != 0)
		{
			break;
		}

		sem_wait(&waitDebut);

		sem_getvalue(&stop, &stopValue);
		if(stopValue != 0)
		{
			break;
		}



		cout << "I'm a puce " << this->id << " !" << " nombre aléatoire : " << distribution(generator) << endl;

		sem_post(&DLpuce::nbPuceWait);
	}
}

void DLpuce::go()
{
	sem_post(&waitDebut);
}

void DLpuce::join()
{
	sem_post(&this->waitDebut);
	sem_post(&stop);
	DLthread::join();
}

int DLpuce::getNbrPuceWaiting()
{
	int nbrPuceWaiting;

	sem_getvalue(&DLpuce::nbPuceWait, &nbrPuceWaiting);

	return nbrPuceWaiting;
}

void DLpuce::resetPuceWaitCounter()
{
	sem_init(&DLpuce::nbPuceWait, 0, 0);
}
