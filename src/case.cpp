/*
 * Case.cpp
 *
 *  Created on: Nov 22, 2014
 *      Author: gurdil
 */

#include "case.h"

DLCase::DLCase(): dog(false), puce(NULL), pound(0)
{
	sem_init(&sem, 0, 1);

}

DLCase::~DLCase()
{
	sem_destroy(&sem);
}

void DLCase::setDog()
{
	dog = true;
}

void DLCase::setPound(char pound)
{
	this->pound = pound;
}

DLpuce* DLCase::getPuce()
{
	return puce;
}

bool DLCase::getDog()
{
	return this->dog;
}

void DLCase::setPuce(DLpuce *puce)
{
	sem_wait(&sem);

	this->puce = puce;

	sem_post(&sem);
}

char DLCase::getPound()
{
	return this->pound;
}
