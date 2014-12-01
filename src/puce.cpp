/*
 * puce.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "puce.h"
#include "DLControler.h"

int DLpuce::nbPuce = 0;
sem_t DLpuce::nbPuceWait;

DLpuce::DLpuce(DLControler *controler) :
		DLthread(),
		stop(),
		generator(std::chrono::system_clock::now().time_since_epoch().count()),
		distribution(-3,3),
		controler(controler)
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
	std::uniform_int_distribution<int> distPosNeg(0,1);
	std::uniform_int_distribution<int> distSizeJump(1,3);
	int jumpX;
	int jumpY;
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

		jumpX = distSizeJump(generator);
		jumpY = distSizeJump(generator);

		jumpX = distPosNeg(generator)>0 ? jumpX : -jumpX;
		jumpY = distPosNeg(generator)>0 ? jumpY : -jumpY;

		controler->setPuce(jumpX, jumpY, this);



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
